/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:01:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/06 19:26:26 by tkeil            ###   ########.fr       */
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
	std::vector<std::pair<int, int>> groups;
    std::vector<int> main;
    std::deque<int> pend;

	static unsigned int jacobsthal(unsigned int n);
	static unsigned int extractNum(std::string const &str);

public:
    PmergeMe(int argc, char **arg);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run();
	void orderGroup();
    
    class Error : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

#endif
