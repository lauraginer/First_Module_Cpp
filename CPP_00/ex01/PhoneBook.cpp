/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:32:49 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/19 21:22:12 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>

void PhoneBook::addContact()
{
	Contact contact; //creamos el objeto
	std::string input = "";
	bool first_iteration = true;
	
	while(input.empty()) //habria que repetir en cada llamada
	{
		if (!first_iteration) {
			std::cout << "Can't be empty!" << std::endl;
		}
		std::cout << "Enter first name:\n";
		std::getline(std::cin, input); //guardamos la entrada en nueva str
		first_iteration = false;
	}
	contact.setFirstName(input);
	std::cout << "Enter last name:\n";		
	std::getline(std::cin, input); //guardamos la entrada en nueva str
	contact.setLastName(input);
	std::cout << "Enter nickname:\n";		
	std::getline(std::cin, input); //guardamos la entrada en nueva str
	contact.setNickname(input);
	std::cout << "Enter phone number:\n";	
	std::getline(std::cin, input); //guardamos la entrada en nueva str
	contact.setPhoneNumber(input);
	std::cout << "Enter a darkest secret!\n:";
	std::getline(std::cin, input); //guardamos la entrada en nueva str
	contact.setDarkestSecret(input);
}		

int PhoneBook::createPhonebook()
{
	Contact contact;
	
	std::cout << "\nContact saved:" << std::endl;
	std::cout << "Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phonenumber: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Secret: " << contact.getDarkestSecret() << std::endl;
	return (0);
}