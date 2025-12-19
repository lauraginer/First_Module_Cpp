/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:30:05 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/19 20:03:31 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:

	//Getters (obtienen el valor)
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();

	//Setters (modifican el valor)
	int setFirstName(std::string name);
	int setLastName(std::string last);
	int setNickname(std::string nick);
	int setPhoneNumber(std::string phone);
	int setDarkestSecret(std::string secret);
	
    // declaraciones de funciones en teoria
};

#endif