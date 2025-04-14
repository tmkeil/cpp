/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:57:04 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 15:10:27 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constr. called!\n";
}

AMateria::AMateria(std::string &type) : type(type)
{
	std::cout << "AMateria default constr. called!\n";
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destr. called!\n";
}
