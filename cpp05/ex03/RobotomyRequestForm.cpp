/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:32:33 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/24 16:10:08 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm default constr. called!\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constr. called!\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm copying!\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assigning!\n";
	if (this != &other)
    {
        target = other.target;
        AForm::operator=(other);
    }
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called!\n";
	
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    this->robotomyRequest();
}

void RobotomyRequestForm::robotomyRequest() const
{
    std::cout << "Chhhrrrrrrrrrrrrrrrrrrrr...\n";
    if (rand() % 2 == 0)
    {
        std::cout << target << " has been robotomized successfully.\n";
    }
    else
    {
        std::cout << target << " robotmy failed.\n";
    }
}
