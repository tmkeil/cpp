/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:26:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/24 19:06:10 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

bool is_dead(const ScavTrap &obj) { return (obj.getHitPoints() < 1); }

int main() {
	ScavTrap scavtrap("ScavTrap");
	ScavTrap st2("ScavTrap2");

	std::cout << std::endl << "Start\n"
	<< "ScavTrap's health: " << scavtrap.getHitPoints() << std::endl
	<< "ScavTrap2's health: " << st2.getHitPoints()
	<< std::string(2, '\n');
	
	while (1) {
		if (is_dead(scavtrap) || is_dead(st2)) {
			std::cout << "soneone died!" << std::endl;
			break;
		}
		scavtrap.attack(st2.getName());
		st2.takeDamage(scavtrap.getAttackDamage());
		st2.attack(scavtrap.getName());
		if (!is_dead(st2))
			scavtrap.takeDamage(st2.getAttackDamage());
		st2.beRepaired(1);
		scavtrap.beRepaired(1);
		st2.guardGate();
		scavtrap.guardGate();
		std::cout << std::endl
		<< "ScavTrap's health: " << scavtrap.getHitPoints() << std::endl
		<< "ScavTrap2's health: " << st2.getHitPoints()
		<< std::string(2, '\n');
	}
	return (0);	
}
