/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:44:11 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 17:22:09 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), length(0)
{
}

template <typename T>
Array<T>::Array(const unsigned int size) : array(new T[size]), length(size)
{
}

template <typename T>
Array<T>::Array(const Array &other) : array(new T[other.length]), length(other.length)
{
    for (size_t i = 0; i < length; i++)
        array[i] = other.array[i]
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this == &other)
        return (*this);
    if (array)
        delete[] array;
    array = new T[other.length];
    length = other.length;
    if (!array)
        throw AllocationException();
    for (size_t i = 0; i < length; i++)
        array[i] = other.array[i];
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    if (array)
        delete[] array;
}

template <typename T>
const char *Array<T>::AllocationException::what() const throw()
{
    return "Allocation failed";
}
