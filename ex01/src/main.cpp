/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:33:54 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/10/09 01:33:54 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Input must be in one arg." << std::endl;
		return 1;
	}
	std::string	input(av[1]);
	if (!isArgCorrect(input))
	{
		std::cerr << "Input contains invalid input or incorrect operations" << std::endl;
		return 1;
	}
	try 
	{
		rpn(input);
	}
	catch (std::exception const &e) 
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
