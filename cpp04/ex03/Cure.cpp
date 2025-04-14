/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:09:34 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 15:10:10 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
	std::cout << "Cure default constr. called!\n";
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure copying!\n";
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure default destr. called!\n";
}

std::string const &Cure::getType(void) const
{
	return (type);
}

void Cure::use(ICharacter &target)
{	
}

Cure *Cure::clone(void) const
{
	return (new Cure());
}
