/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:26:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/24 19:27:31 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

bool is_dead(const FragTrap &obj) { return (obj.getHitPoints() < 1); }

int main() {
	FragTrap fragtrap("FragTrap");
	FragTrap st2("FragTrap2");

	std::cout << std::endl << "Start\n"
	<< "FragTrap's health: " << fragtrap.getHitPoints() << std::endl
	<< "FragTrap2's health: " << st2.getHitPoints()
	<< std::string(2, '\n');
	
	while (1) {
		if (is_dead(fragtrap) || is_dead(st2)) {
			std::cout << "soneone died!" << std::endl;
			break;
		}
		fragtrap.attack(st2.getName());
		st2.takeDamage(fragtrap.getAttackDamage());
		st2.attack(fragtrap.getName());
		if (!is_dead(st2))
			fragtrap.takeDamage(st2.getAttackDamage());
		st2.beRepaired(1);
		fragtrap.beRepaired(1);
		st2.highFivesGuys();
		fragtrap.highFivesGuys();
		std::cout << std::endl
		<< "FragTrap's health: " << fragtrap.getHitPoints() << std::endl
		<< "FragTrap2's health: " << st2.getHitPoints()
		<< std::string(2, '\n');
	}
	return (0);	
}
