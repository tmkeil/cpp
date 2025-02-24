/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:33:05 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/18 12:54:45 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    initializeZombies( Zombie *zombies, int N, std::string name ) {
    for (int i = 0; i < N; i++) {
        zombies[i] = Zombie(name);
    }
}
