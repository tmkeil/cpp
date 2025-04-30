/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:50:42 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/30 11:22:13 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class Span
{
private:
    unsigned int N;
    T container;
public:
    Span();
    Span(const unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);
    int shortestSpan(T &container);
    int longestSpan(T &container);
    class ContainerFullException : public std::exception
    {
    public:
        const char *what() const throw();
    }
    class NotEnoughElementsException : public std::exception
    {
    public:
        const char *what() const throw();
    }
};

#endif
