/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:00:05 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/28 22:27:57 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
#define A_HPP

#include <iostream>
#include "Base.hpp"

class A : public Base
{
public:
    A();
    A(const A &other);
    A &operator=(const A &other);
    ~A();

    Base * generate(void) const;
};

#endif
