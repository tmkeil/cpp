/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:05:37 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/19 12:56:32 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon      *weapon;
public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();

    void    attack() const;
};
