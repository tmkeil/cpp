/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:38:49 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/12 19:47:48 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constr.
Fixed::Fixed() : fixed(0) {}

// destr.
Fixed::~Fixed() {}

Fixed::Fixed(const int value) { this->fixed = value << Fixed::fract; }

Fixed::Fixed(const float value) {
  this->fixed = roundf(value * (1 << Fixed::fract));
}

int Fixed::toInt(void) const { return (this->fixed >> Fixed::fract); }

float Fixed::toFloat(void) const {
  return ((float)this->fixed / (1 << Fixed::fract));
}

// copy constr.
Fixed::Fixed(const Fixed &other) { *this = other; }

// copy assignment op.
Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other)
    this->fixed = other.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const { return (this->fixed); }

void Fixed::setRawBits(int const raw) { this->fixed = raw; }

// overload stream op.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}

// pre increment overload operator
Fixed &Fixed::operator++() {
  this->fixed++;
  return (*this);
}

// pre decrement overload operator
Fixed &Fixed::operator--() {
  this->fixed--;
  return (*this);
}

// post increment overload operator
Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return (tmp);
}

// pre increment overload operator
Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return (tmp);
}

// arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
  return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const {
  return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const {
  return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const {
  return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator-(void) const {
  return (Fixed(-this->toFloat()));
}

// comparison operators
bool Fixed::operator>(const Fixed &other) const {
  return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const {
  return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const {
  return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const {
  return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const {
  return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const {
  return (this->toFloat() != other.toFloat());
}

// min/max public member funcs
Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return ((a.toFloat() < b.toFloat()) ? a : b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b) {
  return ((a.toFloat() < b.toFloat()) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return ((a.toFloat() > b.toFloat()) ? a : b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b) {
  return ((a.toFloat() > b.toFloat()) ? a : b);
}
