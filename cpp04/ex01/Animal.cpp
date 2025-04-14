/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:33:11 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/11 14:03:38 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Default animal was created!\n";
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal was created!\n";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal was copied!\n";
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal copy assignment was called!\n";
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal was destroyed!\n";
}

void	Animal::makeSound() const
{
	std::cout << type << " is making a sound\n";
}

std::string	Animal::getType(void) const
{
	return (type);
}
