/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:42:09 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/28 19:05:39 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this == &other)
        return *this;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void printChar(const double &num)
{
    if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max() || std::isnan(num) || std::isinf(num))
        std::cout << "char: impossible\n";
    else
    {
        char charV = static_cast<char>(num);
        if (std::isprint(static_cast<unsigned char>(charV)))
            std::cout << "char: '" << charV << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }
}

void ScalarConverter::charCaster(std::string const &input)
{
    char c = input[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    
    printChar(d);
    std::cout << "int: " << i << "\n";
    std::cout << "float: " << f << ".0f\n";
    std::cout << "double: " << d << ".0\n";
}

void ScalarConverter::intCaster(std::string const &input)
{
    int i = std::stoi(input);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    printChar(d);
    std::cout << "int: " << i << "\n";
    std::cout << "float: " << f << ".0f\n";
    std::cout << "double: " << d << ".0\n";
}

void ScalarConverter::floatCaster(std::string const &input)
{
    double part;
    float f = std::stof(input);
    double d = static_cast<double>(f);

    printChar(d);
    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() || std::isnan(d))
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(f) << "\n";
    if (std::isnan(d))
        std::cout << "float: " << f << "f\n";
    else if (std::modf(d, &part) == 0.0)
        std::cout << "float: " << f << ".0f\n";
    else
        std::cout << "float: " << f << "f\n";
    if (std::isnan(d))
        std::cout << "double: " << d << "\n";
    else if (std::modf(d, &part) == 0.0)
        std::cout << "double: " << d << ".0\n";
    else
        std::cout << "double: " << d << "\n";
}

void ScalarConverter::doubleCaster(std::string const &input)
{
    double part;
    double d = std::stod(input);

    printChar(d);
    if (d > static_cast<double>(std::numeric_limits<int>::max()) || d < static_cast<double>(std::numeric_limits<int>::min()) || std::isnan(d))
        std::cout << "int: impossible" << "\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";
    if (std::isnan(d))
        std::cout << "float: " << static_cast<float>(d) << "f\n";
    else if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::lowest())
        std::cout << "float: impossible\n";
    else
    {
        std::cout << "float: " << static_cast<float>(d);
        if (std::modf(d, &part) == 0.0)
            std::cout << ".0f\n";
        else
            std::cout << "f\n";
    }
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << d << "\n";
    else if (std::modf(d, &part) == 0.0)
        std::cout << d << ".0\n";
    else
        std::cout << d << "\n";
}

void ScalarConverter::specialHandling(const std::string &input)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    if (input == "inf" || input == "inff")
    {
        std::cout << "float: inff\n";
        std::cout << "double: inf\n";
    }
    else
    {
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    }
}

void ScalarConverter::invalidHandling(void)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

void ScalarConverter::convert(const std::string &input)
{
    t_type type = getType(input);

    switch (type)
    {
        case CHAR:
            charCaster(input);
            break ;
        case INT:
            intCaster(input);
            break ;
        case FLOAT:
            floatCaster(input);
            break ;
        case DOUBLE:
            doubleCaster(input);
            break ;
        case SPECIAL:
            specialHandling(input);
            break ;
        case INVALID:
            invalidHandling();
            break ;
        default:
            break ;
    }
}
