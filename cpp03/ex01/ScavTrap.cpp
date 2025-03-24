/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:27:57 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/24 19:05:09 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Constructor called: \"" << _name << "\" was created!"
			  << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called: \"" << _name << "\" was destroyed!"
			  << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap Constructor called: \"" << _name << "\" was created!"
			  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) { 
	std::cout << "ScavTrap Copy constructor called: \"" << _name << "\" was created!"
			  << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ScavTrap Assignation operator called: \"" << _name << "\" was created!"
			  << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string &target) {
	if (_energyPoints < 1)
		std::cout << "ScavTrap::attack: " << _name << " has no energyPoints left and can't attack!"
				  << std::endl;
	else if (_hitpoints < 1)
		std::cout << "ScavTrap::attack: " << _name << " is dead and can't attack!" << std::endl;
	else {
		std::cout << "ScavTrap::attack: " << _name << " attacks " << target << ", causing " << _attackDamage
				  << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void ScavTrap::guardGate() {
	if (_hitpoints < 1)
		std::cout << _name << " is dead and can't enter in Gate keeper mode!" << std::endl;
	else {
		if (_guardMode)
			std::cout << _name << " is already in Gate keeper mode!" << std::endl;
		else
			std::cout << _name << " has entered in Gate keeper mode!" << std::endl;
	}
	_guardMode = true;
}
