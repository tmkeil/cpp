/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:26:36 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/24 17:06:35 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("NONAME"), _hitpoints(10), _energyPoints(10), _attackDamage(0) {}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "Constructor called: \"" << _name << "\" was created!"
            << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "Destructor called: \"" << _name << "\" was destroyed!"
            << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) { *this = other; }

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    this->_name = other._name;
    this->_hitpoints = other._hitpoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
  }
  return (*this);
}

void ClapTrap::attack(const std::string &target) {
  if (_energyPoints < 1)
    std::cout << _name << " has no energyPoints left and can't attack!"
              << std::endl;
  else if (_hitpoints < 1)
    std::cout << _name << " is dead and can't attack!" << std::endl;
  else {
    std::cout << _name << " attacks " << target << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
    _energyPoints--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitpoints < 1)
    std::cout << _name << " can't take any damage anymore. It is already dead!"
              << std::endl;
  else {
    std::cout << _name << " takes " << amount << " points of damage!"
              << std::endl;
    _hitpoints -= amount;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints < 1)
    std::cout << _name << " has no energyPoints left and can't be repaired!"
              << std::endl;
  else if (_hitpoints < 1)
    std::cout << _name << " is already dead and can't be repaired!"
              << std::endl;
  else {
    std::cout << _name << " regains " << amount << " points of hitpoints!"
              << std::endl;
    _energyPoints--;
    _hitpoints += amount;
  }
}

std::string const &ClapTrap::getName() const { return (_name); }

void ClapTrap::setAttackDamage(const unsigned int amount) {
  _attackDamage = amount;
}

int ClapTrap::getAttackDamage() const { return (_attackDamage); }

int ClapTrap::getHitPoints() const { return (_hitpoints); }

int ClapTrap::getEnergyPoints() const { return (_energyPoints); }
