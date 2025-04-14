/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:09:34 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 17:14:25 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
	std::cout << "Ice default constr. called!\n";
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice copying!\n";
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice default destr. called!\n";
}

std::string const &Ice::getType(void) const
{
	return (type);
}

void Ice::use(ICharacter &target)
{	
}

Ice *Ice::clone(void) const
{
	return (new Ice());
}
