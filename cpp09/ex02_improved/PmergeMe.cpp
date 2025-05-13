/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:00:44 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/13 13:47:59 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **arg) : N(0), leftover(-1)
{
	
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
	// The used vector saves the state of a pend chain index (was it already pushed to the main or not).
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
	
	// Sorting the groups and insert the pendChain in the mainChain (vector containers for main and pend)
	auto startVec = std::chrono::high_resolution_clock::now();
	orderGroup(mainVec, pendVec, groupsVec);
	insertJacobSequence(mainVec, pendVec, jacobs, usedVec);
	auto endVec = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> vectorSort = endVec - startVec;
	
	// Sorting the groups and insert the pendChain in the mainChain (deque containers for main and pend)
	auto startDeq = std::chrono::high_resolution_clock::now();
	orderGroup(mainDeq, pendDeq, groupsDeq);
	insertJacobSequence(mainDeq, pendDeq, jacobs, usedDeq);
	auto endDeq = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> dequeSort = endDeq - startDeq;
	
	// Printing the sorted main chain:
    std::cout << "After  :   ";
    for (int num : mainVec)
        std::cout << num << " ";
    std::cout << std::endl;
	
	// Printing the time for sorting the numbers as container type vector and deque
	std::cout << "Time to process a range of " << N << " elements with std::vector<int> : " << vectorSort.count() << " µs\n";
	std::cout << "Time to process a range of " << N << " elements with std:: deque<int> : " << dequeSort.count() << " µs\n";
}

const char *PmergeMe::Error::what() const throw()
{
    return ("Error");
}

// Visualized explanation of the Ford Johnson (merge insertion sort) algorithm:
// recursively merge sorting the groups (visualized)
/*
5  89  14  2  991 13  84  16  77  80  99  11  112  46  82  3 712  29  64  20  9

{89 5} {14 2}    {991 13} {84 16} {80 77}           {99 11} {112 46} {82 3} {712 29} {64 20} 				({9} => leftover)

({14 2} {89 5})  ({80 77} {84 16} {991 13})         ({99 11} {112 46})  ({64 20} {82 3} {712 29})

({14 2} {80 77} {84 16} {89 5} {991 13})              ({64 20} {82 3} {99 11} {112 46} {712 29})

({14 2} {64 20} {80 77} {82 3} {84 16} {89 5} {99 11} {112 46} {712 29} {991 13})
*/

/* after merge sorting the groups, the main chain looks like this:
14, 64, 80, 82, 84, 89, 99, 112, 712, 991
and the pend chain like this:
2, 20, 77, 3, 16, 5, 11, 46, 29, 13  => (10 indexes that means we need as many jacobs numbers as the last jacobs number is bigger than the last index of the pend chain => (11 > 10))
*/

/*
Then the numbers from the pend chain are inserted in the main chain, using the jacobs sequence (0, 1, 3, 5, 11, 21, 43, 85, 171, 341, ...)
That means the numbers from the pend chain are inserted in that order:
2 (0), 20 (1), 3 (3), 5 (5)
after that, the rest from the pend chain is inserted in the main chain in descending oder:
13 (9), 29 (8), 46 (7), 11 (6), 16 (4), 77 (2)
*/
