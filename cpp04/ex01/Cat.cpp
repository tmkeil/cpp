/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:36:35 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/11 19:43:58 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->brain = new Brain();
	std::cout << "Cat was created!\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat was copied!\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat copy assignment was called!\n";
	return (*this);
}

Cat::~Cat()
{
	if (brain)
		delete brain;
	std::cout << "Cat was destroyed and it's brain too!\n";
}

void	Cat::makeSound() const
{
	std::cout << type << " is making a sound\n";
}

void Cat::setOwnIdea(std::string &idea, int index)
{
	if (index >= NUM_IDEAS)
		std::cout << "Index must be lower than 100\n";
	else if (index < 0)
		std::cout << "index must be greater than 0\n";
	else
		this->brain->setIdea(idea, index);
}

std::string Cat::getOwnIdea(int index) const
{
	if (index >= NUM_IDEAS)
		std::cout << "Index must be lower than 100\n";
	else if (index < 0)
		std::cout << "index must be greater than 0\n";
	else
		return (this->brain->getIdea(index));
	return ("");
}
