/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:50:42 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 14:37:08 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// template function
template <typename T, typename F>
void iter(T *array, size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

// explicit example function
// void iter(void *array, size_t length, void (*f)(void *))
// {
//     for (size_t i = 0; i < length; i++)
//     {
//         f(static_cast<void**>(array)[i]);
//     }
// }

#endif
