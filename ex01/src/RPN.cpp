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

bool	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

bool	isArgCorrect(std::string const &arg)
{
	for (size_t i = 0; i < arg.length(); i++)
	{
		if (!isdigit(arg[i]) && !isOperator(arg[i]) && arg[i] != ' ')
			return false;
		if (i != arg.length() && ((isdigit(arg[i]) || isOperator(arg[i])) && arg[i + 1] != ' '))
			return false;
	}
	return true;
}

void	rpn(std::string &arg)
{
	std::stack<int>	pile;
	int	i = 0;

	while (arg[i])
	{
		if (isdigit(arg[i]))
			
	}
}

