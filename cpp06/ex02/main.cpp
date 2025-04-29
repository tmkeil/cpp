/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:12:58 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/29 13:38:21 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
    int random = std::rand() % 3;
    if (random == 0)
        return (new A());
    else if (random == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "p is A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "p is B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "p is C\n";
}

void identify(Base &p)
{
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "p is A\n";
    }
    catch (...)
    {
    }

    try
    {
        dynamic_cast<B &>(p);
        std::cout << "p is B\n";
    }
    catch (...)
    {
    }

    try
    {
        dynamic_cast<C &>(p);
        std::cout << "p is C\n";
    }
    catch (...)
    {
    }
}

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Base **bases = new Base *[10];

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
