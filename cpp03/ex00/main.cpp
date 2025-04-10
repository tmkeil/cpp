/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:26:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/10 17:12:08 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

bool is_dead(const ClapTrap &obj) { return (obj.getHitPoints() < 1); }

int main() {
	std::cout << "\n===== ClapTrap Test Start =====\n" << std::endl;

	ClapTrap claptrap1("Clappy");
	ClapTrap claptrap2("Trappy");

	claptrap1.setAttackDamage(3);
	claptrap2.setAttackDamage(3);

	std::cout << "Initial Stats:\n";
	std::cout << claptrap1.getName() << " HP: " << claptrap1.getHitPoints() << std::endl;
	std::cout << claptrap2.getName() << " HP: " << claptrap2.getHitPoints() << "\n" << std::endl;

	claptrap1.attack(claptrap2.getName());
	claptrap2.takeDamage(claptrap1.getAttackDamage());

	claptrap2.attack(claptrap1.getName());
	claptrap1.takeDamage(claptrap2.getAttackDamage());

	claptrap1.beRepaired(2);
	claptrap2.beRepaired(2);

	std::cout << "\nFinal Stats:\n";
	std::cout << claptrap1.getName() << " HP: " << claptrap1.getHitPoints() << std::endl;
	std::cout << claptrap2.getName() << " HP: " << claptrap2.getHitPoints() << std::endl;

	std::cout << "\n===== ClapTrap Test End =====\n" << std::endl;

	return 0;
}
