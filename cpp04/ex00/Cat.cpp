/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:36:35 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 13:00:00 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat was created!\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat was copied!\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Cat copy assignment was called!\n";
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat was destroyed!\n";
}

void	Cat::makeSound() const
{
	std::cout << type << " is making a sound\n";
}
