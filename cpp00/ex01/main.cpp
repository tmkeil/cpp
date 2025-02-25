/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:07:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/25 14:17:00 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// using namespace std;

void	ft_clear_screen(void)
{
	std::cout << std::string(100, '\n');
}

void	ft_add_contact(PhoneBook &phonebook)
{
	int	index;

	std::string data[5];
	std::cout << BOLD "Enter first name: " RESET << std::flush;
	std::getline(std::cin, data[0]);
	std::cout << BOLD "Enter last name: " RESET << std::flush;
	std::getline(std::cin, data[1]);
	std::cout << BOLD "Enter nickname: " RESET << std::flush;
	std::getline(std::cin, data[2]);
	std::cout << BOLD "Enter phone number: " RESET << std::flush;
	std::getline(std::cin, data[3]);
	std::cout << BOLD "Enter darkest secret: " RESET << std::flush;
	std::getline(std::cin, data[4]);
	std::cout << std::endl;
	index = phonebook.getCount() % 8;
	phonebook.addContact(data);
	std::cout << CYAN BOLD << "Contact added:" RESET << std::string(2, '\n');
	phonebook.printContact(index);
	std::cout << RESET;
}

int	valid_input(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
		{
			std::cout << "invalid index" << std::endl;
			return (0);
		}
	}
	return (1);
}

void	ft_search_contact(PhoneBook &phonebook)
{
	size_t	index;

	std::string input;
	std::stringstream ss;
	if (phonebook.getCount() == 0)
	{
		std::cout << YELLOW BOLD "No contacts added yet to search for!" RESET << std::endl;
		return ;
	}
	phonebook.printContacts(phonebook);
	std::cout << BOLD "Enter index: " RESET << std::flush;
	std::getline(std::cin, input);
	std::cout << std::endl;
	ss.str(input);
	if (!(ss >> index))
	{
		std::cout << BOLD RED "invalid input!" RESET << std::endl;
		std::cout << std::endl;
		return ;
	}
	phonebook.printContact(index);
}

// void	ft_search_contact(PhoneBook &phonebook)
// {
// 	int	index;
// 	int	id;

// 	std::string input;
// 	std::cout << "Enter index: " << std::flush;
// 	std::getline(std::cin, input);
// 	if (!valid_input(input))
// 		return ;
// 	id = std::atoi(input.c_str());
// 	ft_clear_screen();
// 	phonebook.printContact(id);
// }

int	main(void)
{
	PhoneBook	phonebook;

	std::string command;
	while (1)
	{
		std::cout << std::endl << "Enter a command (" GREEN "ADD" RESET "," GREEN " SEARCH" RESET "," GREEN " EXIT" RESET "): " << std::flush;
		std::getline(std::cin, command);
		std::cout << std::endl;
		if (command.compare("ADD") == 0 || command.compare("add") == 0)
			ft_add_contact(phonebook);
		else if (command.compare("SEARCH") == 0
			|| command.compare("search") == 0)
			ft_search_contact(phonebook);
		else if (command.compare("EXIT") == 0 || command.compare("exit") == 0)
			break ;
		else
			std::cout << RED BOLD "INVALID INPUT" RESET << std::endl;
	}
	return (0);
}
