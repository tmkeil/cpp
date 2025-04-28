/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:50:49 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/28 15:44:25 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{ 
    if (argc != 2)
    {
        std::cerr << "Error: Wrong number of arguments => ./program <value>\n";        
        return (1);
    }
    const std::string input(argv[1]);
    ScalarConverter::convert(input);
    return (0);
}
