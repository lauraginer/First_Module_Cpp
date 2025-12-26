/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:32:49 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/26 22:50:05 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

// Constructor
PhoneBook::PhoneBook() : count(0), index(0), totalContacts(0)
{
}

// Fuction ADD
void PhoneBook::addContact()
{
	Contact contact;
	std::string input;
	
	checkEmpty(input, "Enter a first name:\n");
	contact.setFirstName(input);
	checkEmpty(input, "Enter a last name:\n");
	contact.setLastName(input);
	checkEmpty(input, "Enter a nickname:\n");
	contact.setNickname(input);
	while(1)
	{
		checkEmpty(input, "Enter a phone number:\n");
		if(parseNumber(input) == 0)
		{	
			contact.setPhoneNumber(input);
			break;
		}
	}
	checkEmpty(input, "Enter a darkest secret!:\n");
	contact.setDarkestSecret(input);
	contact.setId(totalContacts);
	saveContact(contact);
}

void PhoneBook::checkEmpty(std::string &input, std::string message)
{
	while(1)
	{
		std::cout << message;
		std::getline(std::cin, input);
		if(input.empty())
			std::cout << "Can't be empty!\n";
		else
			break;
	}
}

int PhoneBook::parseNumber(std::string &phone)
{
	int i = 0;
	while(phone[i])
	{
		if(isalpha(phone[i]) != 0)
		{
			std::cout << "Wrong number!\n";
			return (1);
		}
		if((phone[i] >= 33 && phone[i] <= 47) || (phone[i] >= 58 && phone[i] <= 64) || (phone[i] >= 91 && phone[i] <= 96))
		{
			std::cout << "Can't accept special characters!\n";
			return (1);
		}
		i++;
	}
	return (0);
}

void PhoneBook::saveContact(Contact contact)
{
    contacts[index] = contact; //index apunta a donde va el proximo contacto
    index = (index + 1) % 8; //el resto siempre va a dar el mismo numero hasta llegar al 8
    if (count < 8)
        count++;
    totalContacts++;  // sumamos al contador real
}

// Fuction SEARCH
int PhoneBook::createPhonebook()
{
	int i = 0;
	if (count == 0)
    {
        std::cout << "\nPhonebook is empty! Add contacts first.\n" << std::endl;
        return (1);
    }
	std::cout << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while(i < count)
	{
		std::cout << "|" << std::setw(10) << std::right << contacts[i].getId() << "|"
		<< std::setw(10) << std::right << truncateField(contacts[i].getFirstName()) << "|"
		<< std::setw(10) << std::right << truncateField(contacts[i].getLastName()) << "|"
		<< std::setw(10) << std::right << truncateField(contacts[i].getNickName()) << "|"
   		<< std::endl;
		i++;
	}
	return (0);
}

std::string PhoneBook::truncateField(std::string field)
{
	std::string newStr; //utilizamos field. lo que sea porque std::string es una clase!!!
	if (field.length() > 10)
	{
		newStr = field.substr(0, 9) + "."; //extraemos la subcadena
		return (newStr);
	}
	newStr = field;
	return (newStr);
}

int PhoneBook::enterIndex(std::string input)
{
	int i = 0;
	if(parseNumber(input) == 1)  // Si hay error, retorna
		return (1);
	int idx = std::atoi(input.c_str());
	while(i < count)
	{
		if(contacts[i].getId() == idx)
		{
			std::cout << "\nFirst name: " << contacts[i].getFirstName() << std::endl;
			std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
			std::cout << "Nickname: " << contacts[i].getNickName() << std::endl;
			std::cout << "Phone number: " << contacts[i].getPhoneNumber() << std::endl;
			std::cout << "Dark secret: " << contacts[i].getDarkestSecret() << std::endl;
			return (0);
		}
		i++;
	}
	std::cout << "Wrong index!\n";
	return (1);
}
