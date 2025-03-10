/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:30:22 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 18:46:21 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {
  std::cout << "[ DEBUG ]\nHARL::debug" << std::string(2, '\n');
}

void Harl::info(void) {
  std::cout << "[ INFO ]\nHARL::info" << std::string(2, '\n');
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]\nHARL::warning" << std::string(2, '\n');
}

void Harl::error(void) {
  std::cout << "[ ERROR ]\nHARL::error" << std::string(2, '\n');
}

void Harl::complain(Harl::levels level) {
  void (Harl::*fun_ptrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                     &Harl::error};

  switch (level) {
  case Harl::levels::DEBUG: {
    for (size_t i = Harl::levels::DEBUG; i < 4; i++)
      (this->*fun_ptrs[i])();
    break;
  }
  case Harl::levels::INFO: {
    for (size_t i = Harl::levels::INFO; i < 4; i++)
      (this->*fun_ptrs[i])();
    break;
  }
  case Harl::levels::WARNING: {
    for (size_t i = Harl::levels::WARNING; i < 4; i++)
      (this->*fun_ptrs[i])();
    break;
  }
  case Harl::levels::ERROR: {
    for (size_t i = Harl::levels::ERROR; i < 4; i++)
      (this->*fun_ptrs[i])();
    break;
  }
  default: {
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
    break;
  }
  }
}
