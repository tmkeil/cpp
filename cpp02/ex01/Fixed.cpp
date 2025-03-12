/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:38:49 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/12 16:19:20 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->fixed = value << Fixed::fract;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->fixed = roundf(value * (1 << Fixed::fract));
}

int Fixed::toInt(void) const {
	return (this->fixed >> Fixed::fract);
}

float Fixed::toFloat(void) const {
	return ((float)this->fixed / (1 << Fixed::fract));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignation operator called" << std::endl;
	if (this != &other)
		this->fixed = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (this->fixed);
}

void Fixed::setRawBits(int const raw) {
	this->fixed = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
