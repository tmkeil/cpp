/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:02:35 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/30 11:27:23 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename T>
Span<T>::Span() : N(0)
{
}

template <typename T>
Span<T>::Span(const unsigned int n) : N(n)
{
}

template <typename T>
Span<T>::Span(const Span &other) : N(other.N)
{
    for (auto it = other.container.begin(); it != other.container.end(); it++)
        container.push_back(*it);
}

template <typename T>
Span<T> &Span<T>::operator=(const Span &other)
{
    if (this == &other)
        return *this;
    N = other.N;
    for (auto it = other.container.begin(); it != other.container.end(); it++)
        container.push_back(*it);
    return *this;
}

template <typename T>
Span<T>::~Span()
{
}

template <typename T>
void Span<T>::addNumber(int n)
{
    if (container.size() >= N)
        throw ContainerFullException();
    container.push_back(n);
}

template <typename T>
int Span<T>::shortestSpan(T &container)
{
    if (container.size() < 2)
        throw NotEnoughElementsException();
    int shortest = 0;
    auto start = std::vector<int>::iterator container.begin();
    auto end = std::vector<int>::iterator container.begin();

    while (start != end)
    {
        if ()
    }
    return (shortest);
}

template <typename T>
int Span<T>::longestSpan(T &container)
{
    if (container.size() < 2)
        throw NotEnoughElementsException();
    int longest = INT_MAX;
    auto start = std::vector<int>::iterator container.begin();
    auto end = std::vector<int>::iterator container.begin();

    while (start != end)
    {
        if ()
    }
    return (longest);
}

template <typename T>
const char *Span<T>::ContainerFullException::what() const throw()
{
   return ("Container is already full.");
}

template <typename T>
const char *Span<T>::NotEnoughElementsException::what() const throw()
{
   return ("Container doesn't have enough elements.");
}
