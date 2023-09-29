/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:39:55 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/28 17:39:55 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <map>
# include <string>

class	IncorrectDateOrValueException : public std::exception 
{
public:
	virtual char const *what(void) const throw()
	{
		return "Date or value is incorrect";
	}
};

std::map<std::string, float>	FillMap(std::ifstream &ifs);
void	BitcoinExchange(std::map<std::string, float> &data, std::ifstream &ifs);

#endif
