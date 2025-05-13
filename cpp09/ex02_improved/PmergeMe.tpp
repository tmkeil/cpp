/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:45:21 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/13 20:54:02 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_TPP
#define PMERGE_ME_TPP

#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::getPairs(T &pairsContainer, int argc, char **argv)
{
	for (int i = 0; i < argc - 1; i++)
		pairsContainer.push_back(std::make_pair(extractNum(argv[i]), extractNum(argv[i + 1])));
}

template <typename T>
T PmergeMe::merge(T &a, T &b)
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

	T one(pairs.begin(), pairs.begin() + pairs.size() / 2);
	T two(pairs.begin() + pairs.size() / 2, pairs.end());
	mergeSortPairs(one);
	mergeSortPairs(two);
	pairs = merge(one, two);
}

template <typename T>
void PmergeMe::getJacobsSequence(T &jacobsContainer)
{
	size_t prev1 = 1, prev2 = 0, current = 0;
	
	if (N / 2 < 2)
		return ;
	jacobsContainer.push_back(0);
	while (true)
	{
		current = prev1 + 2 * prev2;
		if (current >= N / 2)
			break;
		jacobsContainer.push_back(current);
		prev2 = prev1;
		prev1 = current;
	}
}


template <typename Iterator>
Iterator PmergeMe::bin_search(Iterator start, Iterator end, const int val)
{
	Iterator low = start;
	Iterator high = end;
	while (low < high)
	{
		Iterator mid = low + (high - low) / 2;
		if (val < *mid)
			high = mid;
		else
			low = mid + 1;
	}
	return (low);
}

template <typename T, typename Pairs>
void PmergeMe::insertJacobSequence(T &mainChain, T &jacobsSequence, Pairs &pairs)
{
	for (auto pair : pairs)
		mainChain.push_back(pair.first);

	int prev_jac = -1, added = 0, i, val, jacob_index, limit;
	for (int idx : jacobsSequence)
	{
		i = 0;
		while (idx - i >= 0 && idx - i > prev_jac)
		{
			jacob_index = idx - i;
			val = pairs[jacob_index].second;
			limit = std::min(jacob_index + added, static_cast<int>(mainChain.size()));
			mainChain.insert(bin_search(mainChain.begin(), mainChain.begin() + limit, val), val);
			added++;
			i++;
		}
		prev_jac = idx;
	}
	for (int i = pairs.size() - 1; i > static_cast<int>(prev_jac); i--)
	{
		val = pairs[i].second;
		mainChain.insert(bin_search(mainChain.begin(), mainChain.end(), val), val);
	}
	if (leftover != -1)
		mainChain.insert(bin_search(mainChain.begin(), mainChain.end(), leftover), leftover);
}

#endif
