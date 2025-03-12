/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:37:20 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/12 19:47:27 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

class Fixed {
private:
  int fixed;
  static const int fract = 8;

public:
  Fixed();
  ~Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &other);

  Fixed &operator=(const Fixed &other);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  int toInt(void) const;
  float toFloat(void) const;

  Fixed &operator++();
  Fixed &operator--();
  Fixed operator++(int);
  Fixed operator--(int);

  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;
  Fixed operator-() const;

  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

typedef struct s_point {
  Fixed x;
  Fixed y;
  s_point(const Fixed x, const Fixed y) : x(x), y(y) {}
} t_point;

typedef struct s_angle {
  t_point A;
  t_point B;
  t_point C;
  s_angle(const t_point A, const t_point B, const t_point C) : A(A), B(B), C(C) {}
} t_angle;
