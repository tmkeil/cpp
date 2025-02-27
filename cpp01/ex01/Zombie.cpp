/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:33:05 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/26 13:56:31 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name): _name(name) {}

Zombie::~Zombie() {}

void Zombie::announce() const {
    std::cout << this->_name << + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void initializeZombies(Zombie* zombies, int N, std::string name) {
  for (int i = 0; i < N; i++) {
    zombies[i] = Zombie(name);
  }
}
