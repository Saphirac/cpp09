/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:41:44 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/10/09 01:41:44 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <cstdlib>
#include <climits>

bool	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

bool	isArgCorrect(std::string &arg)
{
	for (size_t i = 0; i < arg.length(); i++)
	{
		if (!isdigit(arg[i]) && !isOperator(arg[i]) && arg[i] != ' ')
			return false;
		if (i != arg.length() && ((isdigit(arg[i]) || isOperator(arg[i])) && (arg[i + 1] != ' ' && arg[i + 1] != '\0')))
			return false;
	}
	return true;
}

void	makeOperation(std::stack<int> &pile, char c)
{
	long result = 0;
	int nb1 = pile.top();
	pile.pop();
	int nb2 = pile.top();
	pile.pop();

	if (c == '+')
		result = nb1 + nb2;
	else if (c == '-')
		result = nb2 - nb1;
	else if (c == '/')
	{
		if (nb2 == 0)
			throw OperationProblem();
		result = nb2 / nb1;
	}
	else if (c == '*')
		result = nb1 * nb2;

	if (result > INT_MAX || result < INT_MIN)
		throw OperationProblem();
	pile.push(result); // Mettre le résultat dans la pile
}

void	rpn(std::string &arg)
{
	std::stack<int>	pile;
	int	i = 0;

	while (arg[i])
	{
		if (isdigit(arg[i]))
			pile.push(static_cast<int>(arg[i] - '0'));
		if (isOperator(arg[i]) && pile.size() < 2)
			throw OperationProblem();
		else if (isOperator(arg[i]))
			makeOperation(pile, arg[i]);
		i++;
	}
	if (pile.size() != 1)
		throw OperationProblem();
	else
		std::cout << pile.top() << '\n';
}

