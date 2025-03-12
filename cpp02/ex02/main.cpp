/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:42:48 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/12 17:47:53 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  Fixed const x(2.3f);
  Fixed const y(1.2f);
  Fixed const x2(10.123456789f);
  Fixed const y2(10.123456789f);

  std::cout << "\nown tests:\n";
  std::cout << ((x > y) ? "true" : "false") << std::endl;
  std::cout << ((x2 == y2) ? "true" : "false") << std::endl;
}
