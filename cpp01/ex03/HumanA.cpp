/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:17:12 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/19 12:49:22 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): name(name), weapon(&weapon) {
}

HumanA::~HumanA()
{
}

void    HumanA::attack(void) const {
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
