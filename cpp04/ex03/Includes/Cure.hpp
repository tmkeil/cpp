/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:08:40 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 15:18:17 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "ICharacter.hpp"

class Cure
{
private:
	std::string type;

public:
	Cure();
	Cure(std::string &type);
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();

	std::string const &getType() const;
	virtual Cure* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
