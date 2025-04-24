/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:32:11 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/24 13:12:15 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm default constr. called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constr. called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm copying!\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assigning!\n";
	if (this != &other)
    {
        target = other.target;
        AForm::operator=(other);
    }
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called!\n";
	
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    this->shrubberyCreation();
}

void ShrubberyCreationForm::shrubberyCreation() const
{
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file.\n";
        return ;
    }
    file << "\\\\\n"
         << "       ccee88oo\n"
         << "  C8O8O8Q8PoOb o8oo\n"
         << " dOB69QO8PdUOpugoO9bD\n"
         << "CgggbU8OU qOp qOdoUOdcb\n"
         << "    6OuU  /p u gcoUodpP\n"
         << "      \\\\\\//  /douUP\n"
         << "        \\\\\\\\//\n"
         << "         |||/\\\\\n"
         << "         |||\\/\\\n"
         << "         |||||\n"
         << "   .....//||||\\....\n";
    file.close();
    std::cout << "Shrubbery created in " << target << "_shrubbery\n";
}
