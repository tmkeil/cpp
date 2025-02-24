/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:37:25 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/24 17:45:42 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>

class Contact
{
  private:
	std::string first;
	std::string last;
	std::string nick;
	std::string number;
	std::string secret;

  public:
	Contact();
	~Contact();
	void setContact(std::string data[5]);
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickname(void);
	std::string getNumber(void);
	std::string getSecret(void);
};

#endif
