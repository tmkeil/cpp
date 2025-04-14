/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:31:03 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 14:08:33 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::string idea;

	// Creating the array of objects
	Animal** objs = new Animal*[NUM_ANIMALS];
	
	// Creating the Dog and Cat objects
	for (size_t i = 0; i < NUM_ANIMALS; i++)
	{
		if (i < NUM_ANIMALS / 2)
			objs[i] = new Dog();
		else
			objs[i] = new Cat();
		std::cout << std::endl;
	}
	
	// Setting the ideas for each Cat and Dog object in the Animal objects array
	for (size_t i = 0; i < NUM_ANIMALS; i++)
	{
		for (size_t j = 0; j < NUM_IDEAS; j++)
		{
			if (i < NUM_ANIMALS / 2)
			{
				idea = "Dog's idea nbr. " + std::to_string(j);
				static_cast<Dog*>(objs[i])->setOwnIdea(idea, j);
			}
			else
			{
				idea = "Cat's idea nbr. " + std::to_string(j);
				static_cast<Cat*>(objs[i])->setOwnIdea(idea, j);
			}
		}
	}

	// Getting the ideas of each object
	for (size_t i = 0; i < NUM_ANIMALS; i++)
	{
		for (size_t j = 0; j < NUM_IDEAS; j++)
		{
			if (i < 5)
				std::cout << static_cast<Dog*>(objs[i])->getOwnIdea(j) << std::endl;
			else
				std::cout << static_cast<Cat*>(objs[i])->getOwnIdea(j) << std::endl;
		}
		std::cout << std::endl;
	}
	
	// Deleting the Cat and Dog objects in the Animal objects array
	std::cout << "\nDeleting the Cat and Dog objects in the Animal objects array\n";
	for (size_t i = 0; i < NUM_ANIMALS; i++)
		delete objs[i];

	// Deleting the Animal objects array
	std::cout << "\nDeleting the Animal objects array\n";
	delete[] objs;
	
	return 0;
}
