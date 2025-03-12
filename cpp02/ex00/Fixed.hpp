/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:37:20 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/12 14:49:28 by tkeil            ###   ########.fr       */
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
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  int getRawBits(void) const;
  void setRawBits(int const raw);
};
