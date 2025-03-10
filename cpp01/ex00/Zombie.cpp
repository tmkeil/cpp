/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:46:22 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 13:30:04 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie::Zombie() = delete;
Zombie::Zombie() : name("NONAME") { this->announce(); }

Zombie::Zombie(std::string name) : name(name) { this->announce(); }

Zombie::~Zombie(void) {
  std::cout << this->name + " was destroyed" << std::endl;
}

void Zombie::announce(void) const {
  std::cout << this->name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}
