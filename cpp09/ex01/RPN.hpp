/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:50:42 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/14 19:03:45 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <regex>
#include <limits>

class RPN
{
private:
    RPN();
    std::stack<int> stack;
    
    int add(const int &a, const int &b);
    int substract(const int &a, const int &b);
    int multiply(const int &a, const int &b);
    int divide(const int &a, const int &b);

public:
    RPN(const char *arg);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    void run(const char *arg);
    int extractNum(std::string const &str);
    int switchIt(const char c, const int &a, const int &b);

    class Error : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class Overflow : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class Division : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

#endif
