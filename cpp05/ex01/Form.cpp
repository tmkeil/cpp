/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:39:38 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/23 17:16:50 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), _isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "Form default constr. called!\n";
}

Form::Form(const std::string &name, const int signGrade, const int executeGrade)
	: name(name), _isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "Form constr. called!\n";
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other)
	: name(other.name), _isSigned(other._isSigned),
	  signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "Form copying!\n";
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form assigning!\n";
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called!\n";
}

std::string const &Form::getName() const
{
	return (name);
}

bool Form::isSigned() const
{
	return (_isSigned);
}

int Form::getSignGrade() const
{
	return (signGrade);
}

int Form::getExecuteGrade() const
{
	return (executeGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	else if (bureaucrat.getGrade() < 1)
		throw GradeTooHighException();
	else if (_isSigned)
		throw FormAlreadySignedException();
	else
		_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return ("Form is already signed!");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << "\n";
	out << "Sign grade: " << form.getSignGrade() << "\n";
	out << "Execute grade: " << form.getExecuteGrade() << "\n";
	out << "is signed: " << (form.isSigned() ? "true" : "false") << "\n";
	return (out);
}
