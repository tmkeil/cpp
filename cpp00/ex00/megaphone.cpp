/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:58:35 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/13 17:31:53 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// using namespace std;

int main(int argc, char **argv)
{
  int i = 1;

  while (i < argc)
    std::cout << argv[i++];
  if (argc < 2)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  std::cout << std::endl;
  return (0);
}
