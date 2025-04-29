/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:24:24 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 14:37:32 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(const int &x)
{
    std::cout << x << " ";
}

void printString(const std::string &str)
{
    std::cout << str << " ";
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, printInt);
    std::cout << std::endl;

    std::string strs[] = {"Hello", "World", "!"};
    iter(strs, 3, printString);
    std::cout << std::endl;
}
