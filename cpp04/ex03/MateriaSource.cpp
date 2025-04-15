/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:02:33 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/15 17:56:36 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << " MateriaSource's default constructor called!\n";
	for (size_t i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copying!\n";
	for (size_t i = 0; i < 4; i++)
	{
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource assignment operator!\n";
	if (this == &other)
		return (*this);
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

MateriaSource::~MateriaSource()
{
	std::cout << " MateriaSource's destructor called!\n";
	for (size_t i = 0; i < 4; i++)
	{
		if (materias[i])
			delete materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (!materias[i])
			{
				materias[i] = m;
				std::cout << "learned the materia: " << m->getType() << "\n";
				break;
			}
			if (i == 3)
				std::cout << "can't learn materias because it already has 4 materias!\n";
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 3; i >= 0; i--)
	{
		if (materias[i] && type == materias[i]->getType())
		{
			std::cout << "created the materia: " << materias[i]->getType() << "\n";
			return (materias[i]->clone());
		}
	}
	return (NULL);
}
