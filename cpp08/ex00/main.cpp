/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:50:49 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 20:51:39 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    vec.push_back(9);
    vec.push_back(10);
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 4);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
