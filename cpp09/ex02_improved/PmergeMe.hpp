/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:01:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/13 16:48:30 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <regex>
#include <utility>
#include <deque>
#include <chrono>

class PmergeMe
{
private:
    PmergeMe();
	
	int N;
	int	leftover;
	
	// vector
	std::vector<int> jacobsVec;
	std::vector<std::pair<int, int>> groupsVec;
	std::vector<int> mainChainVec;

	// deque
	std::deque<int> jacobsDeq;
	std::deque<std::pair<int, int>> groupsDeq;
	std::deque<int> mainChainDeq;

	template <typename T>
	void getPairs(T &pairsContainer, int argc, char **argv);

	template <typename T>
	T merge(T &a, T &b);
	
	template <typename T>
	void mergeSortPairs(T &pairs);

	template <typename T>
	void getJacobsSequence(T &jacobsContainer);
	
	template <typename T>
	void insertJacobSequence(T &mainChain, T &jacobsSequence);
	
	unsigned int extractNum(std::string const &str);
	void printSorted();
	void printUnsorted(int argc, char **argv);
	void printTime(std::chrono::duration<double, std::micro> vectorSort, std::chrono::duration<double, std::micro> dequeSort);

public:
    PmergeMe(int argc, char **arg);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();
    
    class Error : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

#include "PmergeMe.tpp"

#endif
