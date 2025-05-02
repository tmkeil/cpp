/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:02:35 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/02 18:12:51 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
}

Span::Span(const unsigned int N) : N(N)
{
}

Span::Span(const Span &other) : N(other.N)
{
	for (std::vector<int>::const_iterator it = other.container.begin(); it != other.container.end(); it++)
		container.push_back(*it);
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	N = other.N;
	for (auto it = other.container.begin(); it != other.container.end(); it++)
		container.push_back(*it);
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (container.size() >= N)
		throw ContainerFullException();
	container.push_back(n);
}

int Span::shortestSpan()
{
	if (container.size() < 2)
		throw NotEnoughElementsException();
	std::vector<int> tmp = container;
	std::sort(tmp.begin(), tmp.end());
	int shortest = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size() - 1; i++)
	{
		int diff = tmp[i + 1] - tmp[i];
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (container.size() < 2)
		throw NotEnoughElementsException();
	std::vector<int> tmp = container;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::ContainerFullException::what() const throw()
{
	return ("Container is already full.");
}

const char *Span::NotEnoughElementsException::what() const throw()
{
	return ("Container doesn't have enough elements.");
}

const char *Span::OutOfRangeException::what() const throw()
{
	return ("Index is out of range.");
}

int const &Span::operator[](int index)
{
	if (index >= static_cast<int>(N) || index < 0)
		throw OutOfRangeException();
	return (container[index]);
}
