/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:33:05 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 14:53:42 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() { std::cout << this->_name + " was destroyed" << std::endl; }

void Zombie::announce() const {
  std::cout << this->_name << +": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { this->_name = name; }
