/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:07:05 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/07 16:06:35 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::orderGroup(T &mainChain, T &pendChain, std::vector<std::pair<int, int>> &pairs)
{
	std::cout << "unordered pairs:\n";
	for (auto &i : pairs)
	{
		std::cout << " {" << i.first << " " << i.second << "}";
	}
	std::cout << std::endl;
	
	// Sort: In each pair inside the vector of pairs, the smaller number will be the first and the larger the second.
	for (auto &pair : pairs)
	{
		if (pair.first > pair.second)
			std::swap(pair.first, pair.second);
	}
	
	// Sort: Now the pairs itself will be sorted in ascending order, according to the second number in each pair.
    std::sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int> &b) {
        return (a.second < b.second);
    });
	
	std::cout << "ordered pairs:\n";
	for (auto &i : pairs)
	{
		std::cout << " {" << i.first << " " << i.second << "}";
	}
	std::cout << std::endl;
	
	// Now the larger numbers will be pushed in the main chain and the smaller in the pend chain.
	for (auto &pair : pairs)
	{
		mainChain.push_back(pair.second);
		pendChain.push_back(pair.first);
	}
	
	// The first number from the pend chain is smaller than every number in the main chain. So it can directly be pushed to the main chain.begin().
	mainChain.insert(mainChain.begin(), pendChain.front());

	std::cout << "mainChain:\n";
	for (auto &i : mainChain)
	{
		std::cout << " " << i;
	}
	std::cout << std::endl;
	
	std::cout << "pendChain:\n";
	for (auto &i : pendChain)
	{
		std::cout << " " << i;
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::insertJacobSequence(T &mainChain, T &pendChain, const std::vector<unsigned int> &jacobs, std::vector<bool> &used)
{
	// The first number out of pendChain was already pushed to main. So it will be set to true (don't push it again).
	used[0] = true;
	
	std::cout << "jacobs sequence:\n";
	for (auto &i : jacobs)
	{
		std::cout << " " << i;
	}
	std::cout << std::endl;
	
	// The numbers from the pend chain will be inserted in the main in the jacobsthal sequence and all indexes before, if they weren"t pushed to main yet.
	for (int idx : jacobs)
	{
		while (idx >= 0 && !used[idx])
		{
			int val = pendChain[idx];
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), val), val);
			used[idx] = true;
			idx--;
		}
	}
	
	// If there was an odd number of input numbers, the leftover will be inserted at the end in the main chain
	if (leftover != -1)
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), leftover), leftover);
}
