/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:30:22 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 18:30:16 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) { std::cout << "HARL::debug" << std::endl; }

void Harl::info(void) { std::cout << "HARL::info" << std::endl; }

void Harl::warning(void) { std::cout << "HARL::warning" << std::endl; }

void Harl::error(void) { std::cout << "HARL::error" << std::endl; }

void Harl::complain(std::string level) {
  void (Harl::*fun_ptrs[4])(void);
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  fun_ptrs[0] = &Harl::debug;
  fun_ptrs[1] = &Harl::info;
  fun_ptrs[2] = &Harl::warning;
  fun_ptrs[3] = &Harl::error;
  for (size_t i = 0; i < 4; i++) {
    if (level == levels[i]) {
      (this->*fun_ptrs[i])();
      break;
    }
  }
}
