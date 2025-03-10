/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:30:15 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/10 16:41:18 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl instance;

	instance.complain("DEBUG");
	instance.complain("INFO");
	instance.complain("WARNING");
	instance.complain("ERROR");
	return (0);
}