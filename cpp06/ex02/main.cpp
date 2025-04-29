/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:12:58 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 13:28:14 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate()
{
    int random = std::rand() % 3;
    if (random == 0)
        return (new A());
    else if (random == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p)
{
    
}

void identify(Base& p)
{

}

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Base** bases = new Base*[10];
    
    for (size_t i = 0; i < 10; i++)
    {
        bases[i] = generate();
        if (i % 2)
            identify(bases[i]);
        else
            identify(*bases[i]);
    }

    for (size_t i = 0; i < 10; i++)
    {
        delete (bases[i]);
    }
    
    delete[] bases;
    
    return (0);
}
