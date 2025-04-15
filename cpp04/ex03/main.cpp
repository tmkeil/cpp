/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:20:12 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/15 18:06:30 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
# define TRASH 1000

void	ft_push_trash(AMateria **trash, AMateria *tmp)
{
	for (size_t i = 0; i < TRASH; i++)
	{
		if (trash[i] == NULL)
		{
			trash[i] = tmp;
			break ;
		}
	}	
}

void	ft_delete_trash(AMateria **trash)
{
	for (size_t i = 0; i < TRASH; i++)
	{
		if (trash[i] != NULL)
		{
			delete trash[i];
			trash[i] = NULL;
		}
	}	
}

int main()
{
	std::cout << "======================Creating the Trash with 1000 entries======================\n";
	AMateria **trash = new AMateria*[TRASH];
	for (size_t i = 0; i < TRASH; i++)
		trash[i] = NULL;

	std::cout << "===========================Creating the MateriaSource============================\n";
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;
	
	std::cout << "=============================Creating the Character==============================\n";
	ICharacter *me = new Character("me");
	AMateria *tmp;
	std::cout << std::endl;

	std::cout << "==============================Equipping the Materia===============================\n";
	tmp = src->createMateria("ice");
	me->equip(tmp);
	ft_push_trash(trash, tmp);
	std::cout << std::endl;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	ft_push_trash(trash, tmp);
	std::cout << std::endl;
	
	std::cout << "============================Creating another Character============================\n";
	ICharacter *bob = new Character("bob");
	std::cout << std::endl;

	std::cout << "======================Using the Materia on another Character=======================\n";
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	std::cout << "==============================Unequipping the Materia===============================\n";
	me->unequip(0);
	me->unequip(1);
	std::cout << std::endl;

	std::cout << "============================Deleting the Characters============================\n";
	delete bob;
	delete me;
	std::cout << std::endl;

	std::cout << "============================Deleting the MateriaSource============================\n";
	delete src;
	std::cout << std::endl;

	std::cout << "======================Deleting the Trash with 1000 entries======================\n";
	ft_delete_trash(trash);
	delete[] trash;

	return (0);
}
