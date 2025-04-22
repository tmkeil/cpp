/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:08:30 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/22 18:08:46 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : name("default"), grade(150)
{
	std::cout << "PresidentialPardonForm default constr. called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, int grade)
	: name(name), grade(grade)
{
	std::cout << "PresidentialPardonForm constr. called!\n";
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : name(other.name), grade(other.grade)
{
	std::cout << "PresidentialPardonForm copying!\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm assigning!\n";
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called!\n";
	
}