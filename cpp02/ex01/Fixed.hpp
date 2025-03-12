/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:37:20 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/12 16:18:57 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
  int toInt( void ) const;
  float toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);