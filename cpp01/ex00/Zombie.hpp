/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:46:54 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 13:29:36 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iomanip>
#include <iostream>
#include <string>

class Zombie {
private:
  std::string name;

public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void announce(void) const;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
