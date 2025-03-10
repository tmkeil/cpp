/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:30:20 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 16:36:33 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>

class Harl {
private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

public:
  Harl();
  ~Harl();

  void complain(std::string level);
};

#endif