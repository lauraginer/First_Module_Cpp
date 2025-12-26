/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:32:49 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/26 01:41:38 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>

// Constructor
PhoneBook::PhoneBook() : count(0), index(0), totalContacts(0)
{
}

// Fuction ADD
void PhoneBook::addContact()
{
	Contact contact; //creamos el objeto
	std::string input = "";
	bool first_iteration = true;
	
	checkEmpty(first_iteration, input, "Enter a first name:\n");
	contact.setFirstName(input);
	uploadInput(input, first_iteration);
	checkEmpty(first_iteration, input, "Enter a last name:\n");
	contact.setLastName(input);
	uploadInput(input, first_iteration);
	checkEmpty(first_iteration, input, "Enter a nickname:\n");
	contact.setNickname(input);
	uploadInput(input, first_iteration);
	while(true)
	{
		checkEmpty(first_iteration, input, "Enter a phone number:\n");
		if(parserPhoneNumber(input) == 0)
		{	
			contact.setPhoneNumber(input);
			break;
		}
		uploadInput(input, first_iteration);
	}
	uploadInput(input, first_iteration);
	checkEmpty(first_iteration, input, "Enter a darkest secret!:\n");
	contact.setDarkestSecret(input);
	contact.setId(totalContacts);  // Asignar ID único
	saveContact(contact);
}

void PhoneBook::uploadInput(std::string &input, bool &flag)
{
	input = "";
	flag = true;
}

void PhoneBook::checkEmpty(bool &flag, std::string &input, std::string message)
{
	while(input.empty()) //habria que repetir en cada llamada
	{
		if(!flag)
			std::cout << "Can't be empty!\n";
		std::cout << message;
		std::getline(std::cin, input); //guardamos la entrada en nueva str
		flag = false;
	}
}

int PhoneBook::parserPhoneNumber(std::string &phone)
{
	int value = 0;
	int i = 0;
	
	while(phone[i])
	{
		if(isalpha(phone[i]) != 0)
		{
			std::cout << "Wrong number!\n";
			value = 1;
			break;
		}
		if((phone[i] >= 33 && phone[i] <= 47) || (phone[i] >= 58 && phone[i] <= 64) || (phone[i] >= 91 && phone[i] <= 96))
		{
			std::cout << "Can't accept special characters!\n";
			value = 1;
			break;
		}
		i++;
	}
	return(value);
}

void PhoneBook::saveContact(Contact contact)
{
    contacts[index] = contact; //index apunta a donde va el proximo contacto
    index = (index + 1) % 8; //el resto siempre va a dar el mismo numero hasta llegar al 8
    if (count < 8)
        count++;
    totalContacts++;  // Incrementar contador total
}

// Fuction SEARCH
int PhoneBook::createPhonebook()
{
	int i = 0;
	
	std::cout << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	while(i < count)
	{
		std::cout << "|" << std::setw(10) << std::right << contacts[i].getId() << "|"
		<< std::setw(10) << std::right << contacts[i].getFirstName() << "|"
		<< std::setw(10) << std::right << contacts[i].getLastName() << "|"
		<< std::setw(10) << std::right << contacts[i].getNickName() << "|"
   		<< std::endl;
		i++;
	}
	return (0);
}
