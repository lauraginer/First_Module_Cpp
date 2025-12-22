/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:32:49 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/22 13:18:48 by lginer-m         ###   ########.fr       */
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
	
	checkEmpty(first_iteration, input, "Enter a first name:\n");
	contact.setFirstName(input);
	uploadInput(input, first_iteration);
	checkEmpty(first_iteration, input, "Enter a last name:\n");
	contact.setLastName(input);
	uploadInput(input, first_iteration);
	checkEmpty(first_iteration, input, "Enter a nickname:\n");
	contact.setNickname(input);
	uploadInput(input, first_iteration);
	checkEmpty(first_iteration, input, "Enter a phone number:\n");
	contact.setPhoneNumber(input);
	uploadInput(input, first_iteration);
	checkEmpty(first_iteration, input, "Enter a darkest secret!:\n");
	contact.setDarkestSecret(input);

	std::cout << "\nContact saved:" << std::endl;
	std::cout << "Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phonenumber: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Secret: " << contact.getDarkestSecret() << std::endl;
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
std::string parserPhoneNumber()
{
	std::string input;
	std::getline(std::cin, input); //repasa esta funcion que es rara
	
	//Existe la funcion isdigit!! creo que no hace falta redirigir la salida estandar por aqui sino pasarla por referencia desde el main
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