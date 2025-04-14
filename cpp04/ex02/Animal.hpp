/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:31:14 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 14:11:45 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define NUM_ANIMALS 2

#include <iostream>
#include <iomanip>
#include <string>
#include "Brain.hpp"

class Animal
{
protected:
	Animal();
	Animal(std::string type);
	std::string type;

public:
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif
