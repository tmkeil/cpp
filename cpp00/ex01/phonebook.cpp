/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:08:21 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/24 20:50:17 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0)
{
}

PhoneBook::~PhoneBook()
{
}

size_t PhoneBook::getCount() const
{
	return (count);
}

std::string strFit(std::string str)
{
	return (str.length() > 10 ? str.substr(0, 9) + "." : str);
}

void PhoneBook::addContact(std::string data[5])
{
	contacts[count % 8].setContact(data);
	count++;
}

void PhoneBook::printContact(size_t i)
{
	if (i < 0 || i >= 8 || i >= count)
	{
		std::cout << RED BOLD "Invalid index!" RESET << std::endl;
		return ;
	}
	std::cout << BOLD "First name: " RESET << contacts[i].getFirstName() << std::endl;
	std::cout << BOLD "Last name: " RESET << contacts[i].getLastName() << std::endl;
	std::cout << BOLD "Nickname: " RESET << contacts[i].getNickname() << std::endl;
	std::cout << BOLD "Phone number: " RESET << contacts[i].getNumber() << std::endl;
	std::cout << BOLD "Darkest secret: " RESET << contacts[i].getSecret() << std::endl;
	std::cout << std::string(2, '\n');
}

void PhoneBook::printContacts(PhoneBook phonebook)
{
	std::cout << "|" << std::string(43, '-') << "|" << std::endl;
	std::cout << "|" << BLUE "     Index" RESET << "|";
	std::cout << BLUE "First Name" RESET << "|";
	std::cout << BLUE " Last Name" RESET << "|";
	std::cout << BLUE "  Nickname" RESET << "|";
	std::cout << std::endl;
	std::cout << "|" << std::string(43, '-') << "|" << std::endl;
	for (size_t i = 0; i < phonebook.getCount(); i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << strFit(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << strFit(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << strFit(contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << "|" << std::string(43, '-') << "|" << std::endl;
	std::cout << std::string(2, '\n');
}
