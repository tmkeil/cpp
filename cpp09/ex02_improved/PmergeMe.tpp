/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:45:21 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/13 16:53:00 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_TPP
#define PMERGE_ME_TPP

#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::getPairs(T &pairsContainer, int argc, char **argv)
{
	for (size_t i = 0; i < argc - 1; i++)
	{
		pairsContainer.push_back(std::make_pair(extractNum(argv[i]), extractNum(argv[i + 1])));
	}
}

template <typename T>
T merge(T &a, T &b)
{
	T c;
	size_t i = 0, j = 0;

	while (i < a.size() && j < b.size())
	{
		if (a[i] > b[j])
			c.push_back(b[j]);
		else
			c.push_back(a[i]);
		i++;
		j++;
	}
	while (i < a.size())
		c.push_back(a[i++]);
	while (j < b.size())
		c.push_back(b[j++]);
	return (c);
}

template <typename T>
void PmergeMe::mergeSortPairs(T &pairs)
{
	if (pairs.size() <= 1)
		return ;

	auto one(pairs.begin(), pairs.begin() + pairs.size() / 2);
	auto two(pairs.begin() + pairs.size() / 2, pairs.end());
	one = mergeSortPairs(one);
	two = mergeSortPairs(two);
	pairs = merge(one, two);
}

template <typename T>
void PmergeMe::getJacobsSequence(T &jacobsContainer)
{
	size_t prev1 = 1, prev2 = 1, current = 0;
	
	if (size == 0)
		return ;
	jacobsContainer.push_back(0);
	if (size == 1)
		return ;
	jacobsContainer.push_back(1);
	while (true)
	{
		current = prev1 + 2 * prev2;
		jacobsContainer.push_back(current);
		if (current >= size)
			break;
		prev2 = prev1;
		prev1 = current;
	}
}

template <typename T>
void PmergeMe::insertJacobSequence(T &mainChain, T &jacobsSequence)
{
	
}

#endif
