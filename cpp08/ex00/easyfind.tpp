/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:49:37 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 20:50:50 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

// long version implementation
template <typename T>
typename T::iterator easyfind(T &container, int toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);
    if (it == container.end())
        throw ValueNotFoundException();
    return (it);
}

const char *ValueNotFoundException::what() const throw()
{
    return ("Value not found in container.");
}

// explicit version
//  begin()/end() returns an iterator similar to a pointer.
//  front()/back() returns a reference to the first/last element.

// std::vector<int>::iterator to_find(std::vector<int> &vec, int toFind)
// {
//     std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), toFind);
//     if (it == vec.end())
//         throw ValueNotFoundException();
//     return (it);
// }

#endif
