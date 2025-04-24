/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:32:44 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/24 16:20:32 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    std::cout << "===== INTERN FORM CREATION TEST =====\n";

    Intern intern;
    Bureaucrat boss("boss", 1);

    AForm* shrub = intern.makeForm("ShrubberyCreationForm", "garden");
    AForm* robo = intern.makeForm("RobotomyRequestForm", "Blender");
    AForm* pardon = intern.makeForm("PresidentialPardonForm", "Marvin");
    AForm* unknown = intern.makeForm("UnknownForm", "unknown");

    std::cout << "\nSign and execute tests\n";

    if (shrub)
    {
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        delete shrub;
    }

    std::cout << "\n";

    if (robo)
    {
        boss.signForm(*robo);
        boss.executeForm(*robo);
        delete robo;
    }

    std::cout << "\n";

    if (pardon)
    {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
    }

    std::cout << "\nUnknown form test\n";

    if (!unknown)
    {
        std::cout << "Correctly handled unknown form.\n";
    }
    else
    {
        delete unknown;
    }

    return 0;
}
