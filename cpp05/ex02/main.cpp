/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:32:44 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/24 13:17:56 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    srand(time(NULL));
    std::cout << "\nShrubbery Test:\n";
    try
    {
        Bureaucrat b("b", 130);
        ShrubberyCreationForm shrubbery("garden");
        std::cout << b << shrubbery;
        b.signForm(shrubbery);
        b.executeForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\nRobotomy Test:\n";
    try
    {
        Bureaucrat b("b", 30);
        RobotomyRequestForm rob("rob");
        std::cout << b << rob;
        b.signForm(rob);
        b.executeForm(rob);
        b.executeForm(rob);
        b.executeForm(rob);
        b.executeForm(rob);
        b.executeForm(rob);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\nPresidential Test:\n";
    try
    {
        Bureaucrat b("b", 7);
        PresidentialPardonForm pres("pres");
        std::cout << b << pres;
        b.signForm(pres);
        b.executeForm(pres);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\nGrade too low Test\n";
    try
    {
        Bureaucrat b("b", 151);
        ShrubberyCreationForm shrubbery("garden");
        std::cout << b << shrubbery;
        b.signForm(shrubbery);
        b.executeForm(shrubbery);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\nForm not signed before executing Test\n";
    try
    {
        Bureaucrat b("b", 40);
        ShrubberyCreationForm shrubbery("garden");
        std::cout << b << shrubbery;
        b.executeForm(shrubbery);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
