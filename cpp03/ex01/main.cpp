/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:26:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/10 17:10:49 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

bool is_dead(const ScavTrap &obj) { return (obj.getHitPoints() < 1); }

int main() {
	std::cout << "\n===== ScavTrap Test Start =====\n" << std::endl;

	ScavTrap scavtrap1("Scavy");
	ScavTrap scavtrap2("Gatekeeper");

	std::cout << "Initial Stats:\n";
	std::cout << scavtrap1.getName() << " HP: " << scavtrap1.getHitPoints() << std::endl;
	std::cout << scavtrap2.getName() << " HP: " << scavtrap2.getHitPoints() << "\n" << std::endl;

	scavtrap1.attack(scavtrap2.getName());
	scavtrap2.takeDamage(scavtrap1.getAttackDamage());

	scavtrap2.attack(scavtrap1.getName());
	scavtrap1.takeDamage(scavtrap2.getAttackDamage());

	scavtrap1.beRepaired(10);
	scavtrap2.beRepaired(5);

	scavtrap1.guardGate();
	scavtrap2.guardGate();

	std::cout << "\nFinal Stats:\n";
	std::cout << scavtrap1.getName() << " HP: " << scavtrap1.getHitPoints() << std::endl;
	std::cout << scavtrap2.getName() << " HP: " << scavtrap2.getHitPoints() << std::endl;

	std::cout << "\n===== ScavTrap Test End =====\n" << std::endl;
	return 0;
}
