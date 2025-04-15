/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:04:25 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/15 18:09:15 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("default")
{
	for (size_t i = 0; i < 4; i++)
		materias[i] = NULL;
	std::cout << "Character's default constructor called!\n";
}

Character::Character(std::string name) : name(name)
{
	for (size_t i = 0; i < 4; i++)
		materias[i] = NULL;
	std::cout << "Character's constructor called!\n";
}

Character::Character(const Character &other) : name(other.name)
{
	std::cout << "Character copying!\n";
	for (size_t i = 0; i < 4; i++)
	{
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character assignment operator!\n";
	if (this == &other)
		return (*this);
	name = other.name;
	for (size_t i = 0; i < 4; i++)
	{
		if (materias[i])
		{
			delete materias[i];
			materias[i] = NULL;
		}
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materias[i])
			delete materias[i];
	}
	std::cout << "Character's destructor called!\n";
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materias[i] == NULL)
		{
			materias[i] = m;
			std::cout << "Equipped " << m->getType() << " to " << name << "'s slot " << i << "\n";
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && materias[idx])
	{
		std::cout << "Unequipped " << materias[idx]->getType() << " (Index: " << idx << ") from " << name << "\n";
		materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && materias[idx])
	{
		std:: cout << name << " uses " << materias[idx]->getType() << " on " << target.getName() << "\n";
		materias[idx]->use(target);
	}
}
