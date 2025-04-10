/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:26:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/10 17:01:18 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
int main()
{
	std::cout << "\n===== ClapTrap Test =====" << std::endl;
	ClapTrap ct("Clappy");
	ct.attack("Target A");
	ct.takeDamage(5);
	ct.beRepaired(3);

	std::cout << "\n===== ScavTrap Test =====" << std::endl;
	ScavTrap st("Scavy");
	st.attack("Target B");
	st.takeDamage(10);
	st.beRepaired(5);
	st.guardGate();

	std::cout << "\n===== FragTrap Test =====" << std::endl;
	FragTrap ft("Fraggy");
	ft.attack("Target C");
	ft.takeDamage(15);
	ft.beRepaired(10);
	ft.highFivesGuys();

	std::cout << "\n===== DiamondTrap Test =====" << std::endl;
	DiamondTrap dt("Kevin");

	std::cout << "\nInitial state of DiamondTrap:" << std::endl;
	std::cout << "Name: " << dt.getName() << std::endl;
	std::cout << "HP: " << dt.getHitPoints() << std::endl;
	std::cout << "EP: " << dt.getEnergyPoints() << std::endl;
	std::cout << "AD: " << dt.getAttackDamage() << std::endl;

	std::cout << "\nDiamondTrap attacking FragTrap:" << std::endl;
	dt.attack(ft.getName());
	ft.takeDamage(dt.getAttackDamage());

	std::cout << "\nFragTrap counterattacks DiamondTrap:" << std::endl;
	ft.attack(dt.getName());
	dt.takeDamage(ft.getAttackDamage());

	std::cout << "\nDiamondTrap repairs itself:" << std::endl;
	dt.beRepaired(20);

	std::cout << "\nTesting inherited special abilities:" << std::endl;
	dt.guardGate();
	dt.highFivesGuys();
	dt.whoAmI();

	std::cout << "\n===== Final Stats =====" << std::endl;
	std::cout << "DiamondTrap HP: " << dt.getHitPoints() << std::endl;
	std::cout << "FragTrap HP: " << ft.getHitPoints() << std::endl;

	std::cout << "\n===== End of Test =====" << std::endl;
	return 0;
}
