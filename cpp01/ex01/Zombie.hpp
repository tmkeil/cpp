/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:34:04 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 16:31:42 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

#include <iostream>
#include <string>

class Zombie {
private:
  std::string _name;

public:
  Zombie();
  ~Zombie();
  void announce(void) const;
  void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);
void initializeZombies(Zombie *zombies, int N, std::string name);

#endif