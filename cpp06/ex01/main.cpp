/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:24:24 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/28 21:47:34 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data data(1000, "Hello test\n");

    std::cout << "data address = " << &data << std::endl;
    
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "serialized raw = " << raw << std::endl;

    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "deserialized address = " << deserialized << std::endl;
    std::cout << std::endl;
    std::cout << "deserialized data:" << std::endl;
    std::cout << "number: " << deserialized->number << std::endl;
    std::cout << "text: " << deserialized->text << std::endl;
}
