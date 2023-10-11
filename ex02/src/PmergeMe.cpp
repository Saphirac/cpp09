/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:09:10 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/10/11 21:23:08 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <climits>
#include <algorithm>
#include <iterator>

bool	checkArg(int ac, char **arg)
{
	for (int i = 0; i < ac; i++)
	{
		std::string	current(arg[i]);
		int	prev = -1;
		int	testatol = atol(current);
		if (testatol < 0 || testatol > INT_MAX)
			return false;
		for (int j = 0; current[j]; j++)
			if (!isdigit(current[j]) )
				return false;
		if (prev == testatol)
			return false;
		int	prev = atoi(current);
	}
	return true;
}

std::vector<int>	getVector(int ac, char **arg)
{
	std::vector<int>	ret;

	for (int i = 0; i < ac; i++)
		ret.push_back(atoi(arg[i]));
	return ret;
}

std::list<int>		getList(int ac, char **arg)
{
	std::list<int>	ret;

	for (int i = 0; i < ac; i++)
		ret.push_back(atoi(arg[i]));
	return ret;
}

std::vector<int>	submergeVector(std::vector<int> const &A, std::vector<int> const &B)
{
	std::vector<int>	ret;
	size_t medianA = A.size() / 2, medianB = B.size() / 2;

	if (A.size() == 0)
		return B;
	else if (sizeB.size() == 0)
		return A;

	if (A[medianA] < B[medianB])
	{
		ret.push_back(A[medianA]);
		ret.push_back(B[medianB]);
	} else
	{
		ret.push_back(B[medianB]);
		ret.push_back(A[medianA]);
	}

	std::vector<int> leftA(A.begin(), A.begin() + medianA);
	std::vector<int> rightA(A.begin() + medianA + 1, A.end());
	std::vector<int> leftB(B.begin(), B.begin() + medianB);
	std::vector<int> rightB(B.begin() + medianB + 1, B.end());

	std::vector<int> mergedLeft = submergeVector(leftA, leftB);
	std::vector<int> mergedRight = submergeVector(rightA, rightB);

	ret.insert(ret.end(), mergedLeft.begin(), mergedLeft.end());
	ret.insert(ret.end(), mergedRight.begin(), mergedRight.end());

	return ret;
}

std::vector<int>	mergeVector(std::vector<int> const &arg)
{
	std::vector<int>	ret;
	std::vector<int>	A(arg.begin(), arg.begin() + arg.size() / 2);
	std::vector<int>	B(arg.begin() + arg.size() / 2, arg.end());

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	
	ret = submergeVector(A, B);
	return ret;
}

std::list<int>		submergeList(std::list<int> const &A, std::list<int> const &B)
{
	std::list<int>	ret;

	if (A.empty())
		return B;
	else if (B.empty())
		return A;

	std::list<int>::const_iterator medianA = A.begin();
	std::advance(medianA, A.size() / 2);
	std::list<int>::const_iterator medianB = B.begin();
	std::advance(medianB, B.size() / 2);

	if (*medianA < *medianB)
	{
		ret.push_back(*medianA);
		ret.push_back(*medianB);
	} 
	else
	{
		ret.push_back(*medianB);
		ret.push_back(*medianA);
	}

	std::list<int> leftA(A.begin(), medianA);
	std::list<int> rightA(medianA, A.end());
	rightA.pop_front();
	std::list<int> leftB(B.begin(), medianB);
	std::list<int> rightB(medianB, B.end());
	rightB.pop_front();

	std::list<int> mergedLeft = submergeList(leftA, leftB);
	std::list<int> mergedRight = submergeList(rightA, rightB);

	ret.splice(ret.end(), mergedLeft);
	ret.splice(ret.end(), mergedRight);

	return ret;
}

std::list<int>		mergeList(std::list<int> const &arg)
{
	std::list<int>	ret;
	std::list<int>::iterator	middle = numbers.begin();
	std::advance(middle, numbers.size() / 2);
	std::list<int>	A(numbers.begin(), middle);
	std::list<int>	B(middle, numbers.end());

	A.sort();
	B.sort();

	ret = submergeList(A, B);
	return ret;
}

void	binarySort(std::vector<int> const &vec)
{
	for (int i = 1; i < arr.size(); i++)
	{
		int key = arr[i];
		int left = 0, right = i;

		while (left < right) 
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] < key)
				left = mid + 1;
			else
				right = mid;
		}
		for (int j = i; j > left; j--)
			arr[j] = arr[j - 1];
		arr[left] = key;
	}
}

void	binarySort(std::list<int> const &lst)
{
	for (std::list<int>::iterator i = ++lst.begin(); i != lst.end();)
	{
		int	key = *i;

		std::list<int>::iterator left = lst.begin(), right = i;
		while (left != right)
		{
			std::list<int>::iterator	mid = left;
			std::advance(mid, std::distance(left, right) / 2);

			if (*mid < key)
				left = ++mid;
			else
				right = mid;
		}

		i = lst.erase(i);
		lst.insert(left, key);
	}
}
