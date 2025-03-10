/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:05:37 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 16:32:29 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include "Weapon.hpp"

class HumanA {
private:
  HumanA();
  std::string name;
  Weapon *weapon;

public:
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();

  void attack() const;
};

#endif
