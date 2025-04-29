/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:43:19 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 17:21:18 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
    T       *array;
    size_t  length;
    
public:
    Array();
    Array(const unsigned int size);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    class AllocationException : public std::exception
    {
    public:
        const char *what() const throw();
    };    
};

#endif
