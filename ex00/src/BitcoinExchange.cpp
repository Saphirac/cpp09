/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:37:34 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/29 00:37:34 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>

int		dateMax = 2023;

bool	isDateCorrect(std::string date)
{
	int	count = 0;

	if (date.length() != 10 && std::count(data.begin(), data.end(), '-') != 2)
		return false;
	for (int i = 0; date[i]; i++)
		if (isDigit(date[i]) == false && date[i] != '-')
			return false;
	if (date.find('-', 0) != 4 || date.find('-', 5) != 7)
		return false;
	if (atol(date.substr(0, 4)) > dateMax || atol(date.substr(5, 2) > 12 || atol(date.substr(5, 2) > 31)))
		return false;
}
