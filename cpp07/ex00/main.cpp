/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:50:49 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 14:02:09 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T &param1, T &param2)
{
    int tmp = param1;
    param1 = param2;
    param2 = tmp;
}

template <typename T>
T &min(T &param1, T &param2)
{
    return (param1 < param2 ? param1 : param2);
}

template <typename T>
T &max(T &param1, T &param2)
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
