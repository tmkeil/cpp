/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:28:23 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/24 16:16:16 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::formNames[3] = {
    "ShrubberyCreationForm",
    "RobotomyRequestForm",
    "PresidentialPardonForm"
};

const Intern::FormCreator Intern::formCreators[3] = {
    &Intern::createShrubbery,
    &Intern::createRobotomy,
    &Intern::createPresidential
};

Intern::Intern()
{
    std::cout << "Intern default constr. called!\n";
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copying!\n";
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern assignment!\n";
    if (this == &other)
        return (*this);
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destr. called!\n";
}

AForm *Intern::createShrubbery(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::createUnknown(std::string const &target)
{
    std::cerr << "Unknown form. Didn't create " << target << "\n";
    return (NULL);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
    for (size_t i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << target << "\n";
            return ((this->*formCreators[i])(target));
        }
    }
    return (this->createUnknown(target));
}
