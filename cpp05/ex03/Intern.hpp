/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:28:16 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/24 16:10:00 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    AForm *createUnknown(std::string const &target);
    AForm *createRobotomy(std::string const &target);
    AForm *createShrubbery(std::string const &target);
    AForm *createPresidential(std::string const &target);
    typedef AForm *(Intern::*FormCreator)(std::string const &target);
    static const std::string formNames[3];
    static const FormCreator formCreators[3];
    
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(std::string const &formName, std::string const &target);
};

#endif
