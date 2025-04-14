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
	std::cout << "Cure default constr. called!\n";
}

Cure::Cure(std::string &type) : type(type)
{
	std::cout << "Cure default constr. called!\n";
}

Cure::Cure(const Cure &other)
{
	*this = other;
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
