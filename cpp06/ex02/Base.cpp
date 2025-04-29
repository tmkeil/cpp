/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:59:57 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 13:02:56 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base()
{
}

Base::Base(const Base &other)
{
    *this = other;
}

Base &Base::operator=(const Base &other)
{
    if (this == &other)
        return *this;
    return *this;
}

Base::~Base()
{
}
