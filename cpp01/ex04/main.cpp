/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:00:10 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/22 14:42:50 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

// int main(int argc, char **argv) {
//     std::ifstream   ifs;
//     std::string     line;
//     size_t          pos = 0;
    
//     if (argc != 4)
//         return (1);
//     ifs.open(argv[1], std::ifstream::in);
//     if (!ifs.is_open())
//     {
//         std::cerr << "Error opening file!" << std::endl;
//         return (1);
//     }
//     while (1)
//     {
//         if (!std::getline(ifs, line))
//             break ;
//         pos = 0;
//         while (1)
//         {
//             pos = line.find(argv[2], pos + 1);
//             if (pos != std::string::npos)
//                 break ;
//             std::cout << pos << std::endl;
//         }
//     }
//     return (0);
// }

// int main(void)
// {
//     std::string s = "abc def abc\nabc";
//     size_t      i = 0;
    
//     i = s.find("abc", i);
//     std::cout << i << std::endl;
//     i = s.find("abc", i + 1);
//     std::cout << i << std::endl;
//     i = s.find("abc", i + 1);
//     std::cout << i << std::endl;
//     return (0);
// }

int main(int argc, char **argv)
{
    if (argc != 4)
        return (1);
    std::size_t     pos;
    std::string     line;
    std::ifstream   file_in(argv[1], std::fstream::in);
    std::string     file_o = std::string(argv[1]) + ".replace";
    std::ofstream   file_out(file_o.c_str(), std::ofstream::out);
    while (1)
    {
        pos = 0;
        std::string     result = "";
        if (!std::getline(file_in, line))
            break ;
        while (1)
        {
            pos = line.find(argv[2], pos);
            if (pos == std::string::npos)
                break ;
            result += line.substr(0, pos);
            result += std::string(argv[3]);
            line = line.substr(pos + std::string(argv[2]).size());
        }
        result += line;
        file_out << result << std::endl;
    }  
    file_in.close();
    file_out.close(); 
}
