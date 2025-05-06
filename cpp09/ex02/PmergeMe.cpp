/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:00:44 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/06 18:25:03 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **arg) : leftover(-1)
{
	// if: the numbers were parsed as one string. else: one number as one argument
	if (argc > 2)
    {
        for (int i = 0; i < argc - 1; i += 2)
		{
			int first = extractNum(arg[i]);
			if (i < argc - 2)
			{
				int second = extractNum(arg[i + 1]);
                groups.push_back(std::make_pair(first, second));
			}
			else
				leftover = first;
		}
    }
    else
    {
        std::string input(arg[0]);
        std::regex del("\\s+");
        std::sregex_token_iterator it(input.begin(), input.end(), del, -1);
        std::sregex_token_iterator end;
        while (it != end)
        {
			int first = extractNum(*it);
			if (++it != end)
			{
				int second = extractNum(*it);
				groups.push_back(std::make_pair(first, second));
				++it;
			}
			else
				leftover = first;
        }
    }
    run();
}

PmergeMe::PmergeMe(const PmergeMe &other) : leftover(other.leftover), groups(other.groups), main(other.main), pend(other.pend)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this == &other)
        return *this;
    main = other.main;
    pend = other.pend;
	groups = other.groups;
	leftover = other.leftover;
    return *this;
}

PmergeMe::~PmergeMe()
{
}

// Calculates the jacob number based on n
unsigned int PmergeMe::jacobsthal(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	int prev1 = 1, prev2 = 0, current = 0;
	for (size_t i = 2; i <= n; i++)
	{
		current = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = current;
	}
	return (current);
}

int unsigned PmergeMe::extractNum(std::string const &str)
{
    size_t pos;

    try
    {
        int i = std::stoi(str, &pos);
        if (pos == str.length() && i >= 0)
            return (i);
    }
    catch (...)
    {
    }
    throw Error();
}

void PmergeMe::orderGroup()
{
	// Sort: In each pair inside the vector of pairs, the smaller number will be the first and the larger the second.
	for (auto &pair : groups)
	{
		if (pair.first > pair.second)
			std::swap(pair.first, pair.second);
	}

	// Sort: Now the pairs itself will be sorted in ascending order, according to the second number in each pair.
    std::sort(groups.begin(), groups.end(), [](const std::pair<int, int>& a, const std::pair<int, int> &b) {
        return (a.second < b.second);
    });
	
	// Now the larger numbers will be pushed in the main chain and the smaller in the pend chain.
	for (auto &pair : groups)
	{
		main.push_back(pair.second);
		pend.push_back(pair.first);
	}

	// The first number from the pend chain is smaller than every number in the main chain. So it can directly be pushed to the main chain.begin().
	main.insert(main.begin(), pend.front());
	pend.pop_front();
}

void PmergeMe::run()
{
	// Print the unordered numbers.
	std::cout << "Before: ";
	for (auto pair : groups)
		std::cout << " " << pair.first << " " << pair.second;
	if (leftover != -1)
		std::cout << " " << leftover;
	std::cout << std::endl;
	
	orderGroup();
	
	// Calculating the jacobs sequence and storing it inside jacobs vector.
	// The used vector saves the state of an pend chain index (was it already pushed to the main or not).
	std::vector<unsigned int> jacobs;
	std::vector<bool> used(pend.size(), false);
	for (size_t i = 0; i < pend.size(); i++)
	{
		unsigned int j = jacobsthal(i);
		if (j >= pend.size())
		{
			jacobs.push_back(pend.size() - 1);
			break ;
		}
		jacobs.push_back(j);
	}
	
	// If the last jacobs index was smaller than the last index of the pend chain, then push that last index to the jacobs numbers.
	if (jacobs[jacobs.size() - 1] < pend.size() - 1)
		jacobs.push_back(pend.size() - 1);

	// The numbers from the pend chain will be inserted in the main in the jacobsthal sequence and all indexes before, if they weren"t pushed to main yet.
	for (int idx : jacobs)
	{
		while (idx >= 0 && !used[idx])
		{
			int val = pend[idx];
			auto it = std::lower_bound(main.begin(), main.end(), val);
			main.insert(it, val);
			used[idx] = true;
			idx--;
		}
	}
	
	// If there was an odd number of input numbers, the leftover will be inserted at the end in the main chain
	if (leftover != -1)
	{
		auto it = std::lower_bound(main.begin(), main.end(), leftover);
		main.insert(it, leftover);
	}
	
	// Printing the sorted main chain:
    std::cout << "After:   ";
    for (int num : main)
        std::cout << num << " ";
    std::cout << std::endl;
}

const char *PmergeMe::Error::what() const throw()
{
    return ("Error");
}
