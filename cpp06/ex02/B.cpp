/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:00:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/28 22:25:42 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B()
{
}

B::B(const B &other)
{
    *this = other;
}

B &B::operator=(const B &other)
{
    if (this == &other)
        return *this;
    return *this;
}

B::~B()
{
}

Base * Base::generate(void)
{
    return (new B());
}
