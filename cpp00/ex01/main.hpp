/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:37:25 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/13 17:33:28 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

class Contact
{
private:
    std::string first;
    std::string last;
    std::string nick;
    std::string number;
    std::string secret;
public:
    Contact();
    ~Contact();
    void        setContact(std::string data[5]);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickname(void);
    std::string getNumber(void);
    std::string getSecret(void);
};

class PhoneBook
{
private:
    int         count;
    Contact     contacts[8];
public:
    PhoneBook();
    ~PhoneBook();
    int         getCount(void);
    void        printContact(int i);
    void        addContact(std::string data[5]);
    std::string strFit(std::string str);
};

#endif
