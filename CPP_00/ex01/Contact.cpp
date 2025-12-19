/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:50:56 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/19 21:02:36 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdio>

std::string Contact::getFirstName()
{
	return(firstName);
}
std::string Contact::getLastName()
{
	return(lastName);
}

std::string Contact::getNickName()
{
	return(nickname);
}

std::string Contact::getPhoneNumber()
{
	return(phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return(darkestSecret);
}

//Funciones de setters
int Contact::setFirstName(std::string name)
{
	firstName = name;
	return(0);
}
int Contact::setLastName(std::string last)
{
	if(last.empty()) //getter
	{
		std::cout << "Can't be empty!" << std::endl;
		return(1);
	}
	lastName = last;
	return(0);
}
int Contact::setNickname(std::string nick)
{
	if(nick.empty()) //getter
	{
		std::cout << "Can't be empty!" << std::endl;
		return(1);
	}
	nickname = nick;
	return(0);
}
int Contact::setPhoneNumber(std::string phone)
{
	if(phone.empty()) //getter
	{
		std::cout << "Can't be empty!" << std::endl;
		return(1);
	}
	phoneNumber = phone;
	return(0);
}
int Contact::setDarkestSecret(std::string secret)
{
	if(secret.empty()) //getter
	{
		std::cout << "Can't be empty!" << std::endl;
		return(1);
	}
	darkestSecret= secret;
	return(0);
}

