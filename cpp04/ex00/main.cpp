/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:31:03 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/11 14:27:44 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal *w = new WrongAnimal();
	const WrongAnimal *c = new WrongCat();

	std::cout << w->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	w->makeSound();
	c->makeSound();
	
	delete meta;
	delete i;
	delete j;

	delete w;
	delete c;
	
	return 0;
}
