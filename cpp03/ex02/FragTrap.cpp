/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:27:57 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/24 19:24:15 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Constructor called: \"" << _name << "\" was created!"
			  << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called: \"" << _name << "\" was destroyed!"
			  << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap Constructor called: \"" << _name << "\" was created!"
			  << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) { 
	std::cout << "FragTrap Copy constructor called: \"" << _name << "\" was created!"
			  << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "FragTrap Assignment operator called: \"" << _name << "\" was created!"
			  << std::endl;
	return (*this);
}

void FragTrap::attack(const std::string &target) {
	if (_energyPoints < 1)
		std::cout << "FragTrap::attack: " << _name << " has no energyPoints left and can't attack!"
				  << std::endl;
	else if (_hitpoints < 1)
		std::cout << "FragTrap::attack: " << _name << " is dead and can't attack!" << std::endl;
	else {
		std::cout << "FragTrap::attack: " << _name << " attacks " << target << ", causing " << _attackDamage
				  << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap::highFivesGuys: " << _name << " requests a HIGH-FIVE" << std::endl;
}
