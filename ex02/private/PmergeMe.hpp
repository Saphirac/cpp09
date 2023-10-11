/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:09:13 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/10/11 19:58:36 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <list>

bool	checkArg(int ac, char **arg);

std::vector<int>	getVector(int ac, char **arg);
std::list<int>		getList(int ac, char **arg);

std::vector<int>	mergeVector(std::vector<int> const &a, std::vector<int> const &b);
std::list<int>		mergeList(std::list<int> const &a, std::list<int> const &b);

void	binarySort(std::vector<int> const &vec);
void	binarySort(std::list<int> const &lst);

#endif
