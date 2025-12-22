/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:50:56 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/22 12:18:22 by lginer-m         ###   ########.fr       */
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
void Contact::setFirstName(std::string name)
{
	firstName = name;
	return ;
}
void Contact::setLastName(std::string last)
{
	lastName = last;
	return ;
}
void Contact::setNickname(std::string nick)
{
	nickname = nick;
	return ;
}
void Contact::setPhoneNumber(std::string phone)
{
	phoneNumber = phone;
	return ;
}
void Contact::setDarkestSecret(std::string secret)
{
	darkestSecret = secret;
	return ;
}

