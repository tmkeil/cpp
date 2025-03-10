/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:00:10 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 16:26:39 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int open_files(char *in, std::ifstream &file_in, std::ofstream &file_out) {
  file_in.open(std::string(in));
  if (!file_in.is_open())
    return (0);
  file_out.open(std::string(in) + ".replace", std::ofstream::out);
  if (!file_out.is_open())
    return (file_in.close(), 0);
  return (1);
}

void do_sed(std::ifstream &file_in, std::ofstream &file_out, char *s1,
            char *s2) {
  std::size_t pos;
  std::string line;
  std::string result;

  while (1) {
    pos = 0;
    result = "";
    if (!std::getline(file_in, line))
      break;
    while (1) {
      pos = line.find(s1, pos);
      if (pos == std::string::npos)
        break;
      result += line.substr(0, pos);
      result += std::string(s2);
      line = line.substr(pos + std::string(s1).size());
    }
    result += line;
    file_out << result << std::endl;
  }
}

int main(int argc, char **argv) {
  std::ifstream file_in;
  std::ofstream file_out;
  if (argc != 4) {
    std::cout << "wrong number of parameters [<filename>, <s1>, <s2>] {3}"
              << std::endl;
    return (1);
  }
  if (!open_files(argv[1], file_in, file_out)) {
    std::cout << "error opening file" << std::endl;
    return (1);
  }
  do_sed(file_in, file_out, argv[2], argv[3]);
  file_in.close();
  file_out.close();
}
