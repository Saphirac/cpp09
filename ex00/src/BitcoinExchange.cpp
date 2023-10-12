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
#include <climits>
#include <sstream>
#include <iostream>

bool	isDateCorrect(std::string date)
{
	if (date.length() != 10 || std::count(date.begin(), date.end(), '-') != 2)
		return false;
	if (date.find('-', 0) != 4 || date.find('-', 5) != 7)
		return false;

	for (size_t i = 0; i < date.length(); i++)
		if (!isdigit(date[i]) && date[i] != ' ' && date[i] != '-')
		 return false;

	int month = std::atol(date.substr(5, 2).c_str());
	int day = std::atol(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	return true;
}

bool	isValueCorrect(std::string value)
{
	if (std::count(value.begin(), value.end(), '.') > 1)
		return false;
	for (int i = 0; value[i]; i++)
		if (!isdigit(value[i]) && value[i] != '.')
			return false;
	return true;
}

std::map<std::string, float>	FillMap(std::ifstream &ifs)
{
	std::string line;
	std::string date;
	std::string valuetmp;
	float		value;
	char		*check;
	std::map<std::string, float>	data;

	std::getline(ifs, line);
	while (std::getline(ifs, line)) 
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, ',') && std::getline(iss, valuetmp))
		{
			value = static_cast<float>(strtod(valuetmp.c_str(), &check));
			if (*check != '\0' || !isDateCorrect(date) || !isValueCorrect(valuetmp))
				throw IncorrectDateOrValueException();
		}
		else
			throw IncorrectDateOrValueException();
		data[date] = value;	
	}
	return data;
}

bool	valueError(float value)
{
	if (value > 1000)
	{
		std::cerr << "Error: too large of a number.";
		return false;
	}
	else if (value < 0)
	{
		std::cerr << "Error: not a positive number.";
		return false;
	}
	return true;
}

void	BitcoinExchange(std::map<std::string, float> &data, std::ifstream	&ifs)
{
	std::string	line;
	std::string	date;
	std::string	valueStr;
	float 	value;
	char	*end;
	float	exchangeRate;
	float	result;
	std::map<std::string, float>::const_iterator	it;

	std::getline(ifs, line);
	while (std::getline(ifs, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, '|') && std::getline(iss, valueStr))
		{
			value = static_cast<float>(std::strtod(valueStr.c_str(), &end));
			date = date.substr(0, date.find_last_not_of(" ") + 1);
			if (*end != '\0')
				std::cerr << "Error: problem with conversion => " << valueStr << std::endl;
			else if (!isDateCorrect(date))
				std::cerr << "Error: bad input => " << date << std::endl;
			else if (!isValueCorrect(valueStr))
				std::cerr << "Error: bad input => " << valueStr << std::endl;
			else if (!valueError(value))
				std::cerr << '\n';
			else
			{
				it = data.find(date);

				if (it != data.end())
				{
					exchangeRate = it->second;
					result = value * exchangeRate;
					std::cout << date << " => " << value << " = " << result << '\n';
				}
				else
				{
					std::map<std::string, float>::const_iterator lowerBound = data.lower_bound(date);
					if (lowerBound != data.begin())
					{
						--lowerBound;
						exchangeRate = lowerBound->second;
						result = value * exchangeRate;
						std::cout << date << " => " << value << " = " << result << '\n';
					}
					else
						std::cerr << "Error: bad input => " << date << std::endl;
				}
			}
		}
		else
			std::cerr << "Error: bad input." << std::endl;
	}
}
