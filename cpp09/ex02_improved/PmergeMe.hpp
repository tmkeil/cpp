/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:01:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/12 19:44:53 by tkeil            ###   ########.fr       */
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
	std::
	std::vector<int> jacobsVec;
	std::vector<std::pair<int, int>> groupsVec;

	// deque
	std::deque<int> jacobsDeq;
	std::deque<std::pair<int, int>> groupsDeq;
	
    std::vector<int> mainVec;
	std::vector<int> pendVec;
	std::deque<int> mainDeq;
    std::deque<int> pendDeq;

	template <typename T>
	void orderGroup(T &mainChain, T &pendChain, std::vector<std::pair<int, int>> &pairs);

	template <typename T>
	void insertJacobSequence(T &mainChain, T &pendChain, const std::vector<unsigned int> &jacobs, std::vector<bool> &used);
	
	static unsigned int extractNum(std::string const &str);
	static std::vector<unsigned int> jacobsthal(const size_t size);

public:
    PmergeMe(int argc, char **arg);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run();	
    
    class Error : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

#include "PmergeMe.tpp"

#endif
