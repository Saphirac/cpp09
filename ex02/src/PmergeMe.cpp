/* ************************************************************************** */
/*				                                                            */
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
#include <cstdlib>

bool	checkArg(int const ac, char const *const *const arg)
{
	for (int i = 0; i < ac; i++)
	{
		std::string	current(arg[i]);
		int	testatol = atol(current.c_str());
		if (testatol < 0 || testatol > INT_MAX)
			return false;
		for (int j = 0; current[j]; j++)
			if (!isdigit(current[j]) )
				return false;
	}
	return true;
}

std::vector<int>	getVector(int const ac, char const *const *const arg)
{
	std::vector<int>	ret;

	for (int i = 0; i < ac; i++)
		ret.push_back(atoi(arg[i]));
	return ret;
}

std::list<int>		getList(int const ac, char const *const *const arg)
{
	std::list<int>	ret;

	for (int i = 0; i < ac; i++)
		ret.push_back(atoi(arg[i]));
	return ret;
}

int find_in_map(std::vector<std::pair<int, int> > &pairs, int key)
{
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first == key)
			return pairs[i].second;
	}
	return -1;
}

int binarySearch(std::vector<int> &vec, int target, int end)
{
	int start = 0;
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		if (vec[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}


std::vector<int>	sortVector(std::vector<int> &arg)
{
	int n = arg.size();
	if (n < 2)
		return arg;

	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>	larger;
	for (int i = 0; i < n - 1; i += 2)
	{
		if (arg[i] > arg[i + 1])
		{
			larger.push_back(arg[i]);
			pairs.push_back(std::make_pair(arg[i], arg[i + 1]));
		}
		else
		{
			larger.push_back(arg[i + 1]);
			pairs.push_back(std::make_pair(arg[i + 1], arg[i]));
		}
	}

	larger = sortVector(larger);

	std::vector<int>	smaller;
	for (size_t i = 0; i < larger.size(); ++i)
		smaller.push_back(find_in_map(pairs, larger[i]));

	for (size_t i = 0; i < smaller.size(); i++)
	{
		int pos = binarySearch(larger, smaller[i], 2 * i + 1);
		larger.insert(larger.begin() + pos, smaller[i]);
	}

	if (n % 2 != 0)
	{
		int pos = binarySearch(larger, arg[n - 1], larger.size());
		larger.insert(larger.begin() + pos, arg[n - 1]);
	}

	return larger;
}

int binarySearch(std::list<int> &lst, int target, int end)
{
	int start = 0;
	std::list<int>::iterator it = lst.begin();
	while (start < end && it != lst.end())
	{
		int mid = start + (end - start) / 2;
		std::list<int>::iterator midIt = lst.begin();
		std::advance(midIt, mid);
		if (*midIt < target)
			start = mid + 1;
		else
			end = mid;
		it++;
	}
	return start;
}

std::list<int> sortList(std::list<int> const &arg)
{
	int n = arg.size();
	if (n < 2)
		return arg;

	std::vector<std::pair<int, int> >	pairs;
	std::list<int>	larger;
	std::list<int>::const_iterator it = arg.begin();
	for (int i = 0; i < n - 1; i += 2)
	{
		int first = *it; ++it;
		int second = *it; ++it;
		if (first > second)
		{
			larger.push_back(first);
			pairs.push_back(std::make_pair(first, second));
		}
		else
		{
			larger.push_back(second);
			pairs.push_back(std::make_pair(second, first));
		}
	}

	larger = sortList(larger);

	std::list<int>	smaller;
	for (std::list<int>::iterator j = larger.begin(); j != larger.end(); j++)
		smaller.push_back(find_in_map(pairs, *j));

	for (std::list<int>::iterator j = smaller.begin(); j != smaller.end(); j++)
	{
		int pos = binarySearch(larger, *j, 2 * std::distance(smaller.begin(), j) + 1);
		std::list<int>::iterator insertIt = larger.begin();
		std::advance(insertIt, pos);
		larger.insert(insertIt, *j);
	}

	if (n % 2 != 0)
	{
		int pos = binarySearch(larger, arg.back(), larger.size());
		std::list<int>::iterator insertIt = larger.begin();
		std::advance(insertIt, pos);
		larger.insert(insertIt, arg.back());
	}

	return larger;
}
