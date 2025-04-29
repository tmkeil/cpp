/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:50:53 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 20:49:41 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "easyfind.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

class ValueNotFoundException : public std::exception
{
public:
    const char *what() const throw();
};

// long version declaration
template <typename T>
typename T::iterator easyfind(T &container, int toFind);

// shorter modern version
// template <typename T>
// auto easyfind(T& container, int toFind)
// {
//     auto it = std::find(container.begin(), container.end(), toFind);
//     if (it == container.end())
//         throw ValueNotFoundException();
//     return (it);
// }

// explicit version
// std::vector<int>::iterator to_find(std::vector<int> &vec, int toFind);

#include "easyfind.tpp"

#endif
