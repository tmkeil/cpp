/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:34:05 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/26 12:56:43 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>
# include <cstdlib>

class PhoneBook
{
  private:
	size_t count;
	Contact contacts[8];

  public:
	PhoneBook();
	~PhoneBook();
	size_t getCount(void) const;
	void printContact(size_t i);
	void printContacts(PhoneBook& phonebook);
	void addContact(std::string data[5]);
};

std::string strFit(std::string str);

#endif
