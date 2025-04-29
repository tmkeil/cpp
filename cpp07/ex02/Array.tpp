/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:44:11 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 18:40:48 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

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
        array[i] = other.array[i];
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
const char *Array<T>::OutOfRangeException::what() const throw()
{
    return "Index out of range.\n";
}

template <typename T>
size_t Array<T>::size() const
{
    return (length);
}

template <typename T>
T &Array<T>::operator[](const int index) const
{
    if (index >= static_cast<int>(length) || index < 0)
        throw OutOfRangeException();
    return (array[index]);
}

#endif
