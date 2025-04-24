/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:08:30 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/24 12:55:53 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << "PresidentialPardonForm default constr. called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constr. called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm copying!\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm assigning!\n";
	if (this != &other)
    {
        target = other.target;
        AForm::operator=(other);
    }
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called!\n";
	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    this->presidentialPardon();
}

void PresidentialPardonForm::presidentialPardon() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}
