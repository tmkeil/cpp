/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:01:34 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/28 18:45:34 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string &input)
{
    return (input.length() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])));
}

bool ScalarConverter::isSpecial(const std::string &input)
{
    return (input == "inf" || input == "+inf" || input == "-inf" || input == "inff" || input == "+inff" || input == "-inff");
}

t_type ScalarConverter::numType(const std::string &input)
{
    size_t pos;

    try
    {
        std::stoi(input, &pos);
        if (pos == input.length())
            return (INT);
    }
    catch (...) {}
    
    try
    {
        std::stof(input, &pos);
        if (pos == input.length() - 1 && input.back() == 'f')
            return (FLOAT);
    }
    catch (...) {}
    
    try
    {
        std::stod(input, &pos);
        if (pos == input.length())
            return (DOUBLE);        
    }
    catch (...) {}
    
    return (INVALID);
}

t_type ScalarConverter::getType(const std::string &input)
{
    if (isChar(input))
        return (CHAR);
    else if (isSpecial(input))
        return (SPECIAL);
    return (numType(input));
}
