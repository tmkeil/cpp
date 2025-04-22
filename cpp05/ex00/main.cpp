/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:32:44 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/22 14:45:12 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "Creating a Bureaucrat object\n";
	Bureaucrat bureaucrat("John Doe", 1);
	std::cout << bureaucrat << std::endl;
	std::cout << "\nTrying to increment the grade\n";
	try
	{
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\nTrying to decrement the grade\n";
	try
	{
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\nTrying to create a Bureaucrat object with grade 151\n";
	try
	{
		Bureaucrat bureaucrat2("Jane Doe", 151);
		std::cout << bureaucrat2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\nDestructors get called\n";
}
