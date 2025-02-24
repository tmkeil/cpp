/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:08:21 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/06 11:59:59 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(): count(0) {}

PhoneBook::~PhoneBook() {}

int PhoneBook::getCount() {
    return (count);
}

std::string PhoneBook::strFit(std::string str) {
    return (str.length() > 10 ? str.substr(0, 9) + "." : str);
}

void PhoneBook::addContact(std::string data[5]) {
    contacts[count % 8].setContact(data);
    count++;
}

void PhoneBook::printContact(int i) {
    if (i < 0 || i >= 8 || i >= count) {
        std::cout << "Invalid index!" << std::endl;
        return ;
    }
    std::cout
    << std::setw(10) << i << "|"
    << std::setw(10) << strFit(contacts[i].getFirstName()) << "|"
    << std::setw(10) << strFit(contacts[i].getLastName()) << "|"
    << std::setw(10) << strFit(contacts[i].getNickname()) << std::endl;
}
