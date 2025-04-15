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

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constr. called!\n";
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure copying!\n";
}

Cure::~Cure()
{
	std::cout << "Cure default destr. called!\n";
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}
