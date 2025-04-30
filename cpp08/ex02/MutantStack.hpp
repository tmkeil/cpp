/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:43:19 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/30 20:14:38 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>

template <typename T>
class MutantStack
{
private:
    T       stack;
    size_t  length;
    
public:
    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    ~MutantStack();

    T &operator[](const int index) const;

    size_t size() const;
    class OutOfRangeException : public std::exception
    {
    public:
        const char *what() const throw();
    };  
};

#include "MutantStack.tpp"

#endif
