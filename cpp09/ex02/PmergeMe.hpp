/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:01:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/06 14:54:29 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <list>
#include <regex>
#include <utility>

class PmergeMe
{
private:
    PmergeMe();
	int	leftover;
    std::vector<int> temp;
	std::vector<std::pair<int, int>> groups;
    std::vector<int> main;
    std::list<int> pend;

public:
    PmergeMe(int argc, char **arg);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run();
    int extractNum(std::string const &str);
	void groupElementsAndOrder();
    
    class Error : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

#endif
