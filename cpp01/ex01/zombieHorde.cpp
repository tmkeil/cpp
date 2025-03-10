/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:32:48 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 14:53:15 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void initializeZombies(Zombie *zombies, int N, std::string name) {
  for (int i = 0; i < N; i++) {
    zombies[i].setName(name);
    zombies[i].announce();
  }
}

Zombie *zombieHorde(int N, std::string name) {
  Zombie *zombies;

  zombies = new Zombie[N];
  initializeZombies(zombies, N, name);
  return (zombies);
}
