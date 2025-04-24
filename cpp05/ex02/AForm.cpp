/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:39:38 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/24 13:15:36 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), _isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "AForm default constr. called!\n";
}

AForm::AForm(std::string const &name, const int signGrade, const int executeGrade)
	: name(name), _isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "AForm constr. called!\n";
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other)
	: name(other.name), _isSigned(other._isSigned),
	  signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "AForm copying!\n";
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm assigning!\n";
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called!\n";
}

std::string const &AForm::getName() const
{
	return (name);
}

bool AForm::isSigned() const
{
	return (_isSigned);
}

int AForm::getSignGrade() const
{
	return (signGrade);
}

int AForm::getExecuteGrade() const
{
	return (executeGrade);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade too low!");
}

const char *AForm::AFormAlreadySignedException::what() const throw()
{
	return ("AForm is already signed!");
}

const char *AForm::AFormNotSignedException::what() const throw()
{
    return ("AForm is not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << "AForm: " << AForm.getName() << "\n";
	out << "Sign grade: " << AForm.getSignGrade() << "\n";
	out << "Execute grade: " << AForm.getExecuteGrade() << "\n";
	out << "is signed: " << (AForm.isSigned() ? "true" : "false") << "\n";
	return (out);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	else if (bureaucrat.getGrade() < 1)
		throw GradeTooHighException();
	else if (_isSigned)
		throw AFormAlreadySignedException();
	else
		_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned())
        throw AFormNotSignedException();
    if (executor.getGrade() > executeGrade)
        throw GradeTooLowException();
    if (executor.getGrade() < 1)
        throw GradeTooHighException();
}
