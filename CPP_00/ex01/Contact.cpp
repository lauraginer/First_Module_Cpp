/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:50:56 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/18 20:19:09 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

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
void Contact::setFirstName(std::string name)
{
	firstName = name;
}
void Contact::setLastName(std::string last)
{
	lastName = last;
}
void Contact::setNickname(std::string nick)
{
	nickname = nick;
}
void Contact::setPhoneNumber(std::string phone)
{
	phoneNumber = phone;	
}
void Contact::setDarkestSecret(std::string secret)
{
	darkestSecret= secret;	
}
