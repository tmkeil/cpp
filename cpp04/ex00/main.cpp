/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:31:03 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 13:59:10 by tkeil            ###   ########.fr       */
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
	const WrongCat *copy = new WrongCat(*static_cast<const WrongCat*>(c));

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	std::cout << w->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	std::cout << copy->getType() << " " << std::endl;

	meta->makeSound();
	i->makeSound();
	j->makeSound();

	w->makeSound();
	c->makeSound();
	copy->makeSound();
	
	delete meta;
	delete i;
	delete j;

	delete w;
	delete c;
	delete copy;
	
	return 0;
}
