/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:59:49 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/13 21:04:28 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* a;
    Zombie* b;

    Zombie instance;
    randomChump("random1");
    randomChump("random2");
    a = newZombie("hihi");
    b = newZombie("haha");
    delete(a);
    delete(b);
    return (0);
}
