/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:32:44 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/22 17:55:20 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "Form with a valid grade\n";
    try
	{
        Form f("document1", 10, 11);
		std::cout << f << std::endl;
    }
    catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    std::cout << "Form with an invalid grade\n";
    try
	{
        Form f2("document2", 151, 42);
    }
    catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    std::cout << "Tim signs form \"doc\", because Tim's grade is higher than signGrade\n";
    try
	{
        Bureaucrat b("Tim", 1);
        Form s("doc", 50, 30);
        b.signForm(s);
        std::cout << s << std::endl;
    }
    catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    std::cout << "Tim tries to sign form \"doc\". (Not possible, because his grade is lower than signGrade)\n";
    try
	{
        Bureaucrat b("Tim", 100);
        Form s("doc", 50, 30);
        b.signForm(s);
        std::cout << s << std::endl;
    }
    catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
    return 0;
}
