/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:07:50 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/06 11:31:52 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(): first(""), last(""), nick(""), number(""), secret("") {}

Contact::~Contact() {}

void    Contact::setContact(std::string data[5]) {
    first = data[0];
    last = data[1];
    nick = data[2];
    number = data[3];
    secret = data[4];
}

std::string Contact::getFirstName(void) {
    return first;
}

std::string Contact::getLastName(void) {
    return last;
}

std::string Contact::getNickname(void) {
    return nick;
}

std::string Contact::getNumber(void) {
    return number;
}

std::string Contact::getSecret(void) {
    return secret;
}
