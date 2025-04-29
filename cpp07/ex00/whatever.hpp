/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:06:56 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 14:07:41 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &param1, T &param2)
{
    int tmp = param1;
    param1 = param2;
    param2 = tmp;
}

template <typename T>
T &min(T &param1, T &param2)
{
    return (param1 < param2 ? param1 : param2);
}

template <typename T>
T &max(T &param1, T &param2)
{
    return (param1 > param2 ? param1 : param2);
}

#endif
