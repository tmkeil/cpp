/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:26:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/10 17:07:24 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

bool is_dead(const FragTrap &obj) { return (obj.getHitPoints() < 1); }

int main() {
	std::cout << "\n===== FragTrap Test Start =====\n" << std::endl;

	FragTrap fragtrap1("Fraggy");
	FragTrap fragtrap2("Trapster");

	std::cout << "Initial Stats:\n";
	std::cout << fragtrap1.getName() << " HP: " << fragtrap1.getHitPoints() << std::endl;
	std::cout << fragtrap2.getName() << " HP: " << fragtrap2.getHitPoints() << "\n" << std::endl;

	fragtrap1.attack(fragtrap2.getName());
	fragtrap2.takeDamage(fragtrap1.getAttackDamage());

	fragtrap2.attack(fragtrap1.getName());
	fragtrap1.takeDamage(fragtrap2.getAttackDamage());

	fragtrap1.beRepaired(10);
	fragtrap2.beRepaired(5);

	fragtrap1.highFivesGuys();
	fragtrap2.highFivesGuys();

	std::cout << "\nFinal Stats:\n";
	std::cout << fragtrap1.getName() << " HP: " << fragtrap1.getHitPoints() << std::endl;
	std::cout << fragtrap2.getName() << " HP: " << fragtrap2.getHitPoints() << std::endl;

	std::cout << "\n===== FragTrap Test End =====\n" << std::endl;
	return 0;
}
