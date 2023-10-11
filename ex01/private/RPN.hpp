/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:28:55 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/10/09 01:28:55 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class	OperationProblem : public std::exception 
{
public:
	virtual char const *what(void) const throw()
	{
		return "Impossible result value";
	}
};

bool	isArgCorrect(std::string arg);
void	rpn(std::string arg);

#endif
