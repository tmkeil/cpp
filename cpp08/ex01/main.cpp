/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:24:24 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/30 20:06:49 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	srand(time(NULL));
	Span span(NUMBERS);
	std::cout << "Filling the container with random values...\n";
	for (size_t i = 0; i < NUMBERS + 2; i++)
	{
		try
		{
			span.addNumber(rand() % 10000);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << "\nPrinting the container through the operator[]...\n";
	for (size_t i = 0; i < NUMBERS + 2; i++)
	{
		try
		{
			std::cout << span[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	try
	{
		std::cout << "\nshortest span: " << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "longest span: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
