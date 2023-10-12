/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:40:57 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/10/12 02:58:17 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int	main(int const ac, char const *const *const av)
{
	if (ac <= 2)
	{
		std::cerr << "Please input at least 2 numbers." << std::endl;
		return 1;
	}
	if (!checkArg((ac - 1), (av + 1)))
	{
		std::cerr << "Incorrect arguments.\nPlease only input positive integers." << std::endl;
		return 1;
	}
	std::vector<int>	vec = getVector(ac - 1, av + 1);
	std::list<int>		lst = getList(ac - 1, av + 1);
	
	std::clock_t timeVector = std::clock();
	std::vector<int> resultVec = mergeVector(vec);
	binarySort(resultVec);
	timeVector = std::clock() - timeVector;

	std::clock_t timeList = std::clock();
	std::list<int> resultLst = mergeList(lst);
	binarySort(resultLst);
	timeList = std::clock() - timeList;

	std::cout << "Before : ";
	for (int i = 1; i < ac; i++)
		std::cout << av[i] << ' ';
	std::cout << "\nAfter : ";
	std::vector<int>::const_iterator	it;
	for (it = resultVec.begin(); it != resultVec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << "\nTime to sort " << ac - 1
	<< " elements with std::vector : " << static_cast<double>(timeVector) / CLOCKS_PER_SEC  * 1000000
	<< " us \n" << " Time to sort " << ac - 1 << " elements with std::list : "
	<< static_cast<double>(timeList) / CLOCKS_PER_SEC * 1000000 << " us \n";
}
