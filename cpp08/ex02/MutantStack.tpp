/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:15:08 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/02 20:14:26 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// std::stack is a container adaptor that uses another container (default: std::deque)
// This container is stored in a protected member called c.
 
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	if (this == &other)
		return *this;
	std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (this->c.rend());
}
