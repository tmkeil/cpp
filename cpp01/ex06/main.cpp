/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:30:15 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 18:24:07 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::levels get_complaint(std::string complaint) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (size_t i = 0; i < 4; i++) {
    if (complaint == levels[i])
      return ((Harl::levels)i);
  }
  return (Harl::levels::UNDEFINED);
}

void complain(std::string cmplt) {
  Harl harlfilter;
  harlfilter.complain(get_complaint(cmplt));
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "wrong number of args. Please give one of these as input: "
                 "(DEBUG, INFO, WARNING, ERROR)"
              << std::endl;
    return (1);
  }
  complain(std::string(argv[1]));
  return (0);
}
