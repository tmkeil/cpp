/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:50:49 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 13:57:16 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void swap(int &param1, int &param2)
{
    int tmp = param1;
    param1 = param2;
    param2 = tmp;
}

int &min(int &param1, int &param2)
{
    return (param1 < param2 ? param1 : param2);
}

int &max(int &param1, int &param2)
{
    return (param1 > param2 ? param1 : param2);
}

void swap(std::string &param1, std::string &param2)
{
    std::string tmp = param1;
    param1 = param2;
    param2 = tmp;
}

std::string &min(std::string &param1, std::string &param2)
{
    return (param1 < param2 ? param1 : param2);
}

std::string &max(std::string &param1, std::string &param2)
{
    return (param1 > param2 ? param1 : param2);
}

int main(void)
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return (0);
}
