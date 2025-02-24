/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:07:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/06 12:08:13 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

// using namespace std;

void  ft_clear_screen(void)
{
  std::cout << std::string(100, '\n');
}

void  ft_add_contact(PhoneBook &phonebook)
{
  std::string data[5];

  std::cout << "Enter first name: " << std::flush;
  std::getline(std::cin, data[0]);
  std::cout << "Enter last name: " << std::flush;
  std::getline(std::cin, data[1]);
  std::cout << "Enter nickname: " << std::flush;
  std::getline(std::cin, data[2]);
  std::cout << "Enter phone number: " << std::flush;
  std::getline(std::cin, data[3]);
  std::cout << "Enter darkest secret: " << std::flush;
  std::getline(std::cin, data[4]);
  ft_clear_screen();
  phonebook.addContact(data);
}

// void  ft_search_contact(PhoneBook &phonebook)
// {
//   int               index;

//   std::cout << "Enter index: " << std::flush;
//   std::cin >> index;
//   if (std::cin.fail())
//   {
//     std::cin.clear();
//     std::cin.ignore();
//   }
//   std::cin.ignore();
//   phonebook.printContact(index);
// }

void  ft_search_contact(PhoneBook &phonebook)
{
  int               index;
  std::string       input;

  std::cout << "Enter index: " << std::flush;
  std::getline(std::cin, input);
  std::stringstream ss(input);
  if (!(ss >> index))
  {
    std::cout << "invalid input" << std::endl;
    return ;
  }
  ft_clear_screen();
  phonebook.printContact(index);
}

int main(void)
{
  std::string     command;
  PhoneBook       phonebook;

  ft_clear_screen();
  while (1)
  {
    std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);
    ft_clear_screen();
    if (command.compare("ADD") == 0)
      ft_add_contact(phonebook);
    else if (command.compare("SEARCH") == 0)
      ft_search_contact(phonebook);
    else if (command.compare("EXIT") == 0)
      break ;
  }
  return (0);
}
