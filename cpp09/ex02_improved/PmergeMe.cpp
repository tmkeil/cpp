/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:00:44 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/13 16:52:38 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}


PmergeMe::PmergeMe(const PmergeMe &other) : N(0), leftover(other.leftover), jacobsDeq(other.jacobsDeq), groupsDeq(other.groupsDeq), mainChainDeq(other.mainChainDeq), jacobsVec(other.jacobsVec), groupsVec(other.groupsVec), mainChainVec(other.mainChainVec)
{
}

PmergeMe::PmergeMe(int argc, char **arg) : N(argc)
{
	if (argc % 2 == 1)
		leftover = extractNum(arg[argc - 1]);

	auto startVec = std::chrono::high_resolution_clock::now();
	getPairs(groupsVec, argc, arg);
	mergeSortPairs(groupsVec);
	getJacobsSequence(jacobsVec);
	insertJacobSequence(mainChainVec, jacobsVec);
	auto endVec = std::chrono::high_resolution_clock::now();
	
	auto startDeq = std::chrono::high_resolution_clock::now();
	getPairs(groupsDeq, argc, arg);
	mergeSortPairs(groupsDeq);
	getJacobsSequence(jacobsDeq);
	insertJacobSequence(mainChainDeq, jacobsDeq);
	auto endDeq = std::chrono::high_resolution_clock::now();

	printUnsorted(argc, arg);
	printSorted();
	printTime(endVec - startVec, endDeq - startDeq);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this == &other)
        return *this;
	N = other.N;
	
	jacobsDeq = other.jacobsDeq;
	groupsDeq = other.groupsDeq;
	mainChainDeq = other.mainChainDeq;
	
	jacobsVec = other.jacobsVec;
	groupsVec = other.groupsVec;
	mainChainVec = other.mainChainVec;
	
	leftover = other.leftover;
	
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::printUnsorted(int argc, char **argv)
{
	std::cout << "Unsorted: ";
	for (size_t i = 0; i < argc; i++)
	{
		std::cout << " " << argv[i];
	}
	std::cout << std::endl;
}

void PmergeMe::printSorted()
{
	std::cout << "Sorted: ";
	for (size_t i = 0; i < mainChainVec.size(); i++)
	{
		std::cout << " " << mainChainVec[i];
	}
	std::cout << std::endl;
}

void PmergeMe::printTime(std::chrono::duration<double, std::micro> vectorSort, std::chrono::duration<double, std::micro> dequeSort)
{
	std::cout << "Time to process a range of " << N << " elements with std::vector<int> : " << vectorSort.count() << " µs\n";
	std::cout << "Time to process a range of " << N << " elements with std::deque<int> : " << dequeSort.count() << " µs\n";
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
		throw Error();
    }
}

const char *PmergeMe::Error::what() const throw()
{
    return ("Error");
}

// Visualized explanation of the Ford Johnson (merge insertion sort) algorithm:
/*
input: 5  89  14  2  991 13  84  16  77  80  99  11  112  46  82  3 712  29  64  20  (9 => leftover)

pairing (max, min): {89 5} {14 2}    {991 13} {84 16} {80 77}           {99 11} {112 46} {82 3} {712 29} {64 20}

recursively merge sorting the groups (visualized) => https://www.youtube.com/watch?v=4VqmGXwpLqc [Merge sort in 3 minutes]
({14 2} {89 5})  ({80 77} {84 16} {991 13})         ({99 11} {112 46})  ({64 20} {82 3} {712 29})

({14 2} {80 77} {84 16} {89 5} {991 13})              ({64 20} {82 3} {99 11} {112 46} {712 29})

({14 2} {64 20} {80 77} {82 3} {84 16} {89 5} {99 11} {112 46} {712 29} {991 13})
*/

/* after merge sorting the groups, the main chain looks like this (bigger numbers from each pair):
14, 64, 80, 82, 84, 89, 99, 112, 712, 991
and the pend chain like this (smaller numbers from each pair):
2, 20, 77, 3, 16, 5, 11, 46, 29, 13  => (10 indexes that means we need as many jacobs numbers as the last jacobs number is bigger than the last index of the pend chain => (11 > 10))
*/

/*
Then the numbers from the pend chain are inserted in the main chain, using the jacobs sequence (0, 1, 3, 5, 11, 21, 43, 85, 171, 341, ...)
That means the numbers from the pend chain are inserted in that order:
2 (0), 20 (1), 3 (3), 5 (5)
after that, the rest from the pend chain is inserted in the main chain in descending oder:
13 (9), 29 (8), 46 (7), 11 (6), 16 (4), 77 (2)
*/
