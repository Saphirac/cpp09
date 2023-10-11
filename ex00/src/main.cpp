/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:43:41 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/10/09 01:40:13 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int const ac, char const *const *const av)
{
	if (ac != 2)
	{
		std::cerr << "Invalid number of arguments." << std::endl;
		return 1;
	}
	
	std::map<std::string, float>	data;
	std::ifstream	ifs("data.csv");
	if (!ifs.is_open())
	{
		std::cerr << "Can't open data file." << std::endl;
		return 1;
	}
	try {
		data = FillMap(ifs);
	}
	catch (std::exception const &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return 1;
	}
	ifs.close();
	ifs.open(av[1]);
	if (!ifs.is_open())
	{
		std::cerr << "Can't open file.\n";
		return 1;
	}
	BitcoinExchange(data, ifs);
	ifs.close();
	return 0;
}
