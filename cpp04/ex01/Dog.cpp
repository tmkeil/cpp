/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:39:14 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 13:25:38 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Dog was created!\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog was copied!\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Dog copy assignment was called!\n";
	return (*this);
}

Dog::~Dog()
{
	if (brain)
		delete brain;
	std::cout << "Dog was destroyed and it's brain too!\n";
}

void Dog::makeSound() const
{
	std::cout << type << " is making a sound\n";
}

void Dog::setOwnIdea(std::string &idea, int index)
{
	if (index >= NUM_IDEAS)
		std::cout << "Index must be lower than 100\n";
	else if (index < 0)
		std::cout << "index must be greater than 0\n";
	else
		this->brain->setIdea(idea, index);
}

std::string Dog::getOwnIdea(int index) const
{
	if (index >= NUM_IDEAS)
		std::cout << "Index must be lower than 100\n";
	else if (index < 0)
		std::cout << "index must be greater than 0\n";
	else
		return (this->brain->getIdea(index));
	return ("");
}
