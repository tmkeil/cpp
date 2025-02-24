/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:11:17 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/19 12:32:38 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type) {
}

Weapon::~Weapon()
{
}

std::string Weapon::getType() const {
    return (this->type);
}

void        Weapon::setType(std::string type) {
    this->type = type;
}
