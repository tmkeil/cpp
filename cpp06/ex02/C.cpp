/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:59:50 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 13:40:02 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C()
{
}

C::C(const C &other) : Base(other)
{
}

C &C::operator=(const C &other)
{
    if (this == &other)
        return *this;
    return *this;
}

C::~C()
{
}
