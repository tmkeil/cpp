/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:19:26 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/06 14:53:02 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// int main(int argc, char **argv)
// {
//     if (argc < 2)
//     {
//         std::cout << "Wrong number of arguments. [./RPN numbers]\n";
//         return (1);
//     }
//     try
//     {
//         PmergeMe pmerge(argc - 1, argv + 1);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     return (0);
	
// }

#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" \ninto tokens:\n",str);
  pch = strtok (str, " ,.-\t\r\v\f\n");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}