/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:00:44 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/07 16:12:08 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **arg) : N(0), leftover(-1)
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
                groupsVec.push_back(std::make_pair(first, second));
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
				groupsVec.push_back(std::make_pair(first, second));
				++it;
			}
			else
				leftover = first;
        }
    }
	groupsDeq = groupsVec;
	N = groupsVec.size() * 2 + (leftover != -1 ? 1 : 0);
	if (N > 1)
    	run();
	else
		std::cout << "Only one number already sorted.\n";
}

PmergeMe::PmergeMe(const PmergeMe &other) : N(0), leftover(other.leftover), groupsVec(other.groupsVec), groupsDeq(other.groupsDeq), mainVec(other.mainVec), pendVec(other.pendVec), mainDeq(other.mainDeq), pendDeq(other.pendDeq)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this == &other)
        return *this;
	N = other.N;
    mainVec = other.mainVec;
    pendVec = other.pendVec;
	mainDeq = other.mainDeq;
    pendDeq = other.pendDeq;
	groupsVec = other.groupsVec;
	groupsDeq = other.groupsDeq;
	leftover = other.leftover;
    return *this;
}

PmergeMe::~PmergeMe()
{
}

std::vector<unsigned int> PmergeMe::jacobsthal(const size_t size)
{
	std::vector<unsigned int> jacobs;
	size_t prev1 = 1, prev2 = 0, current = 0;
	
	if (size == 0)
		return jacobs;

	jacobs.push_back(0);
	if (size == 1)
		return jacobs;
	
	jacobs.push_back(1);
	
	while (true)
	{
		current = prev1 + 2 * prev2;
		if (current >= size)
			break;
		jacobs.push_back(current);
		prev2 = prev1;
		prev1 = current;
	}
	
	// If the last jacobs index was smaller than the last index of the pend chain, then push that last index to the jacobs numbers.
	if (jacobs.back() < size - 1)
		jacobs.push_back(size - 1);

	return (jacobs);
}

unsigned int PmergeMe::extractNum(std::string const &str)
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

void PmergeMe::run()
{
	// The used vector saves the state of an pend chain index (was it already pushed to the main or not).
	std::vector<bool> usedVec(N / 2, false);
	std::vector<bool> usedDeq(N / 2, false);
	
	// Calculating the jacobs sequence and storing it inside jacobs vector.
	std::vector<unsigned int> jacobs = jacobsthal(N / 2);
		
	// Print the unordered numbers.
	std::cout << "Before : ";
	for (auto pair : groupsVec)
		std::cout << " " << pair.first << " " << pair.second;
	if (leftover != -1)
		std::cout << " " << leftover;
	std::cout << std::endl;
	
	// Sorting the groups and inserting the pend chain in the main for the vector containers
	auto startVec = std::chrono::steady_clock::now();
	orderGroup(mainVec, pendVec, groupsVec);
	insertJacobSequence(mainVec, pendVec, jacobs, usedVec);
	auto endVec = std::chrono::steady_clock::now();
	
	// Sorting the groups and inserting the pend chain in the main for the deque containers
	auto startDeq = std::chrono::steady_clock::now();
	orderGroup(mainDeq, pendDeq, groupsDeq);
	insertJacobSequence(mainDeq, pendDeq, jacobs, usedDeq);
	auto endDeq = std::chrono::steady_clock::now();
	
	// Printing the sorted main chain:
    std::cout << "After  :   ";
    for (int num : mainVec)
        std::cout << num << " ";
    std::cout << std::endl;
	
	// Printing the time for sorting the main/pend chains as container type vector and the time for container type deque
	std::cout << "Time to process a range of " << N << " elements with std::vector<int> : " << std::chrono::duration_cast<std::chrono::microseconds>(endVec - startVec).count() << " us\n";
	std::cout << "Time to process a range of " << N << " elements with std:: deque<int> : " << std::chrono::duration_cast<std::chrono::microseconds>(endDeq - startDeq).count() << " us\n";
}

const char *PmergeMe::Error::what() const throw()
{
    return ("Error");
}
