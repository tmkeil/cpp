/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:06:24 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/11 14:29:29 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "Default WrongAnimal was created!\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal was created!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Animal was copied!\n";
	*this = other;
	
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongAnimal copy assignment was called!\n";
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal was destroyed!\n";
}

void	WrongAnimal::makeSound() const
{
	std::cout << type << " is making a sound\n";
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}
