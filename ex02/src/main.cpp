/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:40:57 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/10/11 20:01:48 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int const ac, char const *const *const av)
{
	if (ac <= 2)
	{
		std::cerr << "Please input at least 2 numbers." << std::endl;
		return 1;
	}
	if (!checkArg((ac - 1), (av + 1)))
	{
		std::cerr << "Incorrect arguments.\n Please only input positive integers and no duplicate." << std::endl;
		return 1;
	}
	std::vector<int>	vec = getVector(av + 1);
	std::list<int>		lst = getList(av + 1);
	
	std::clock_t startVector = std::clock();
	std::vector<int> resultVec = mergeVector(vec);
	binarySort(resultVec);
	std::clock_t endVector = std::clock();

	std::clock_t startList = std::clock();
	std::list<int> resultLst = mergeList();
	binarySort(resultLst);
	std::clock_t endList = std::clock();
}
