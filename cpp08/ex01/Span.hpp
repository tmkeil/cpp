/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:50:42 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/30 19:04:58 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#define NUMBERS 2

class Span
{
private:
    unsigned int N;
    std::vector<int> container;
public:
    Span();
    Span(const unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
	int const &operator[](int index);

    class ContainerFullException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class NotEnoughElementsException : public std::exception
    {
    public:
        const char *what() const throw();
    };
	class OutOfRangeException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

#endif
