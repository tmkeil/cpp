/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:32:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/11 19:39:52 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default brain was created!\n";
}

Brain::~Brain()
{
	std::cout << "Brain was destroyed!\n";
}

Brain::Brain(std::string idea)
{
	std::cout << "Brain was created!\n";
	std::cout << "Setting every idea for the new Brain to " << idea << std::endl;
	for (size_t i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = idea;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain was copied!\n";
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < NUM_IDEAS; i++)
			this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy assignment called!\n";
	return (*this);
}

void Brain::setIdea(std::string &idea, int index)
{
	if (index >= NUM_IDEAS)
		std::cout << "Index must be lower than 100\n";
	else if (index < 0)
		std::cout << "index must be greater than 0\n";
	else
		this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= NUM_IDEAS)
		std::cout << "Index must be lower than 100\n";
	else if (index < 0)
		std::cout << "index must be greater than 0\n";
	else
		return (this->ideas[index]);
	return (NULL);
}
