/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:14:56 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/18 21:05:35 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int addContacts()
{
	Contact contact; //creamos el objeto
	std::string input;
	
	std::cout << "Enter first name:" << std::endl;
	std::getline(std::cin, input); //guardamos la entrada en nueva str
	contact.setFirstName(input); //setter
	if(contact.getFirstName().empty()) //getter
	{
		std::cout << "Can't be empty!" << std::endl;
		return(1);
	}
	
	std::cout << "Enter last name:" << std::endl;;
	std::getline(std::cin, input); //guardamos la entrada en nueva str
	contact.setLastName(input); //setter
	if(contact.getLastName().empty()) //getter
	{
		std::cout << "Can't be empty!" << std::endl;
		return(1);
	}
	std::cout << "Enter nickname:" << std::endl;;
	std::getline(std::cin, input); //guardamos la entrada en nueva str
	contact.setNickname(input); //setter
	if(contact.getNickName().empty()) //getter
	{
		std::cout << "Can't be empty!" << std::endl;
		return(1);
	}
	std::cout << "Enter phone number:" << std::endl;;
	std::getline(std::cin, input); //guardamos la entrada en nueva str
	contact.setPhoneNumber(input); //setter
	if(contact.getPhoneNumber().empty()) //getter
	{
		std::cout << "Can't be empty!" << std::endl;
		return(1);
	}
	std::cout << "Enter a darkest secret!:" << std::endl;;
	std::getline(std::cin, input); //guardamos la entrada en nueva str
	contact.setDarkestSecret(input); //setter
	if(contact.getDarkestSecret().empty()) //getter
	{
		std::cout << "Can't be empty!" << std::endl;
		return(1);
	}

	//para ver si se esta guardando bien
	std::cout << "\nContact saved:" << std::endl;
    std::cout << "Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phonenumber: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Secret: " << contact.getDarkestSecret() << std::endl;
	return (0);
}
//int controlEmpty()
int main(int argc, char **argv)
{
	while(1)
	{
		if(argc == 2)
		{
			std::string cmd = argv[1];
			if(cmd == "ADD")
			{
				if(addContacts() == 0) //supongo que en algun momento tiene que parar cuando se completen los nombres
					return(0);
			}
				
			else if(cmd == "SEARCH")
				std::cout << "SEARCH";
			else if(cmd == "EXIT")
				exit(0);
		}
		else
			std::cout << "Please, enter one option: ADD, SEARCH or EXIT";
	}
	std::cout << std::endl;
	return(0);
}