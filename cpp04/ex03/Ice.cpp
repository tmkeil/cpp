/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:09:34 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 16:01:32 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice default constr. called!\n";
}

Ice::Ice(std::string &type) : type(type)
{
	std::cout << "Ice default constr. called!\n";
}

Ice::Ice(const Ice &other)
{
	*this = other;
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
