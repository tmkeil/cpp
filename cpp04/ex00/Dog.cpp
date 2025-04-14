/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:39:14 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 13:00:21 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog was created!\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog was copied!\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Dog copy assignment was called!\n";
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog was destroyed!\n";
}

void Dog::makeSound() const
{
	std::cout << type << " is making a sound\n";
}
