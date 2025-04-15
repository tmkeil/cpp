/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:57:04 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/15 17:42:14 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("default")
{
	std::cout << "AMateria default constr. called!\n";
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria default constr. called!\n";
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << "AMateria copying!\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria destr. called!\n";
}

std::string const &AMateria::getType(void) const
{
	return (type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* uses " << type << " on " << target.getName() << " *\n";
}
