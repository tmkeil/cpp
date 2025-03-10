/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:05:31 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 16:32:57 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"

class HumanB {
private:
  HumanB();
  std::string name;
  Weapon *weapon;

public:
  HumanB(std::string name);
  ~HumanB();

  void attack() const;
  void setWeapon(Weapon &weapon);
};

#endif
