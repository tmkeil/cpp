/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:26:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/24 17:17:53 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

bool is_dead(const ClapTrap &obj) { return (obj.getHitPoints() < 1); }

int main() {
  ClapTrap claptrap("Claptrap");
  ClapTrap ct2("ClapTrap2");
  claptrap.setAttackDamage(3);
  ct2.setAttackDamage(3);

  std::cout << std::endl << "Start\n"
  << "ClapTrap's health: " << claptrap.getHitPoints() << std::endl
  << "ClapTrap2's health: " << ct2.getHitPoints()
  << std::string(2, '\n');

  while (1) {
    if (is_dead(claptrap) || is_dead(ct2)) {
      std::cout << "soneone died!" << std::endl;
      break;
    }
    claptrap.attack(ct2.getName());
    ct2.takeDamage(claptrap.getAttackDamage());
    ct2.attack(claptrap.getName());
    if (!is_dead(ct2))
      claptrap.takeDamage(ct2.getAttackDamage());
    ct2.beRepaired(1);
    claptrap.beRepaired(1);
    std::cout << std::endl
              << "ClapTrap's health: " << claptrap.getHitPoints() << std::endl
              << "ClapTrap2's health: " << ct2.getHitPoints()
              << std::string(2, '\n');
  }
  return (0);
}
