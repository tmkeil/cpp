/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:58:35 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/25 21:56:25 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

// using namespace std;

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < std::string(argv[i]).size(); j++)
		{
			if (isalpha(argv[i][j]))
				std::cout << static_cast<char>(toupper(argv[i][j]));
			else
				std::cout << argv[i][j];
		}
		if (i < argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}