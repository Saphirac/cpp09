/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:09:13 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/10/13 16:00:26 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <list>

bool	checkArg(int const ac, char const *const *const arg);

std::vector<int>	getVector(int const ac, char const *const *const arg);
std::list<int>		getList(int const ac, char const *const *const arg);

std::vector<int>	sortVector(std::vector<int> &arg);
std::list<int>		sortList(std::list<int> const &arg);

#endif
