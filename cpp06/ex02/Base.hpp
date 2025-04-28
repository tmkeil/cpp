/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:59:00 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/28 22:26:07 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
public:
    Base();
    Base(const Base &other);
    Base &operator=(const Base &other);
    virtual ~Base();

    virtual Base * generate(void) const = 0;
    void identify(Base* p);
    void identify(Base& p);
};

#endif
