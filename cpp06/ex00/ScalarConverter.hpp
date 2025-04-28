/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:38:17 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/28 18:35:27 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cfloat>
#include <sstream>
#include <typeinfo>
#include <exception>

typedef enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    INVALID
} t_type;

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

    static void charCaster(std::string const &input);
    static void intCaster(std::string const &input);
    static void floatCaster(std::string const &input);
    static void doubleCaster(std::string const &input);
    static void specialHandling(std::string const &input);
    static void invalidHandling(void);

    static t_type getType(const std::string &input);
    static t_type numType(const std::string &input);
    static bool isChar(const std::string &input);
    static bool isSpecial(const std::string &input);

public:
    ~ScalarConverter();

    static void convert(const std::string &input);
};

#endif
