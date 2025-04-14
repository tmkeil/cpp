/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:08:40 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/14 15:18:00 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "ICharacter.hpp"

class Ice
{
private:
	std::string type;

public:
	Ice();
	Ice(std::string &type);
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	~Ice();

	std::string const &getType() const;
	virtual Ice *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
