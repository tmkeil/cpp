/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:09:34 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/15 17:50:18 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constr. called!\n";
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice copying!\n";
}

Ice::~Ice()
{
	std::cout << "Ice default destr. called!\n";
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}
