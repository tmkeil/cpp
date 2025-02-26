/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:07:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/26 13:20:24 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// using namespace std;

void get_input(std::string str, std::string &data, bool is_digit) {
  bool val;

  do {
    val = true;
    std::cout << BOLD << str << RESET << std::flush;
    std::getline(std::cin, data);
    if (std::cin.fail())
      exit(0);
    if (is_digit) {
      for (size_t i = 0; i < data.size(); i++) {
        if (!isdigit(data[i])) {
          std::cout << YELLOW "only digits allowed!" RESET
                    << std::string(2, '\n');
          val = false;
          break;
        }
      }
    } else if (!is_digit) {
      for (size_t i = 0; i < data.size(); i++) {
        if (!isalnum(data[i])) {
          std::cout << YELLOW "only alphanumeric character are allowed!" RESET
                    << std::string(2, '\n');
          val = false;
          break;
        }
      }
    }
    if (data.size() == 0) {
      std::cout << YELLOW "field can't be empty" RESET << std::string(2, '\n');
      val = false;
    }
  } while (!val);
}

void ft_add_contact(PhoneBook &phonebook) {
  int index;

  std::string data[5];
  get_input("Enter first name: ", data[0], false);
  get_input("Enter last name: ", data[1], false);
  get_input("Enter nickname: ", data[2], false);
  get_input("Enter phone number: ", data[3], true);
  get_input("Enter darkest secret: ", data[4], false);
  std::cout << std::endl;
  index = phonebook.getCount() % 8;
  phonebook.addContact(data);
  std::cout << CYAN BOLD << "Contact added:" RESET << std::string(1, '\n');
  phonebook.printContact(index);
}

int check_number_size(const std::string &input, size_t &index) {
  unsigned long long nbr;

  std::stringstream ss;
  ss.str(input);
  ss >> nbr;
  if (ss.fail() || nbr > std::numeric_limits<size_t>::max())
    return (0);
  index = static_cast<size_t>(nbr);
  return (1);
}

int is_valid_index(PhoneBook &phonebook, const std::string &input,
                   size_t &index) {

  for (size_t i = 0; i < input.size(); i++) {
    if (!isdigit(input[i])) {
      std::cout << YELLOW BOLD "Error: Only digits allowed!" RESET << std::endl;
      return (0);
    }
  }
  if (!check_number_size(input, index)) {
    std::cout << YELLOW BOLD "Error: Number too large or invalid input!" RESET
              << std::endl;
    return (0);
  }
  if (index >= phonebook.getCount() || index >= 8) {
    std::cout << YELLOW BOLD "Error: No entry with that index!" RESET
              << std::endl;
    return (0);
  }
  return (1);
}

void ft_search_contact(PhoneBook &phonebook) {
  size_t index;

  std::string input;
  if (phonebook.getCount() == 0) {
    std::cout << YELLOW BOLD "No contacts added yet to search for!" RESET
              << std::endl;
    return;
  }
  phonebook.printContacts(phonebook);
  do {
    std::cout << "Enter index: ";
    std::getline(std::cin, input);
    std::cout << std::endl;
  } while (!is_valid_index(phonebook, input, index));
  phonebook.printContact(index);
}

int main(void) {
  PhoneBook phonebook;

  std::string command;
  while (1) {
    std::cout << std::endl
              << "Enter a command (" GREEN "ADD" RESET "," GREEN " SEARCH" RESET
                 "," GREEN " EXIT" RESET "): "
              << std::flush;
    std::getline(std::cin, command);
    if (std::cin.fail())
      return (1);
    std::cout << std::endl;
    if (command.compare("ADD") == 0 || command.compare("add") == 0)
      ft_add_contact(phonebook);
    else if (command.compare("SEARCH") == 0 || command.compare("search") == 0)
      ft_search_contact(phonebook);
    else if (command.compare("EXIT") == 0 || command.compare("exit") == 0)
      break;
    else
      std::cout << RED BOLD "INVALID INPUT" RESET << std::endl;
  }
  return (0);
}
