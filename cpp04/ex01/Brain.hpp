/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:31:48 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 13:18:17 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

# define NUM_IDEAS 2

class Brain
{
private:
	std::string ideas[NUM_IDEAS];

public:
	Brain();
	Brain(std::string idea);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void setIdea(std::string &idea, int index);
	std::string getIdea(int index) const;
};

#endif
