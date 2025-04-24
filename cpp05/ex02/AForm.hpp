/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:39:54 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/24 11:47:22 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool _isSigned;
	const int signGrade;
	const int executeGrade;

public:
	AForm();
	AForm(std::string const &name, int signGrade, int executeGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	~AForm();

	std::string const &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class AFormAlreadySignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
    class AFormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif
