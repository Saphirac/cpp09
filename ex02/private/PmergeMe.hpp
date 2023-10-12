/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:09:13 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/10/12 02:07:29 by mcourtoi         ###   ########.fr       */
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

std::vector<int>	mergeVector(std::vector<int> const &arg);
std::list<int>		mergeList(std::list<int> const &arg);

void	binarySort(std::vector<int> &vec);
void	binarySort(std::list<int> &lst);

#endif
