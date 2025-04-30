/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:19:26 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 18:40:03 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

int main()
{
    srand(time(NULL));
    std::cout << "Creating an Array<int> with " << MAX_VAL << " elements...\n";
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    std::cout << "Filling the array with random values...\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100;
        numbers[i] = value;
        mirror[i] = value;
    }
    
    // Tests assignment operator and copy constructor.
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    std::cout << "\nPrinting values from the array...\n";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << "\n";
        
    std::cout << "\nTest if mirror has the same values...\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "Error: values differ at index " << i << std::endl;
            return 1;
        }
    }
    std::cout << "It has the same values!\n";
    
    std::cout << "\nTest out of range exception:\n";
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception (index -2): " << e.what();
    }

    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception (index MAX_VAL): " << e.what();
    }

    delete[] mirror;

    return 0;
}
