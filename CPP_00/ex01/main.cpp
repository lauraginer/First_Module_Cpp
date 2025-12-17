/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:14:56 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/17 16:39:36 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int GetContacts(std::string input)
{
	Contact contact; //creamos el objeto
	
	std::cout << "Enter first name:";
	std::cin >> contact.FirstName; //acceder al atributo
	
	if(contact.FirstName.empty())
		std::cout << "Can't be empty!" << std::endl;
	
	std::cout << "Enter last name:";
	std::cout << "Enter nickname:";
	std::cout << "Enter phone number:";
	std::cout << "Enter a darkest secret!:";
	return(0);
}
//hay que poner algo de getters y setters para poder acceder a atributos privados
int main(int argc, char **argv)
{
	if(argc == 2)
	{
		std::string cmd = argv[1];
		if(cmd == "ADD")
			std::cout << "ADD";
		else if(cmd == "SEARCH")
			std::cout << "SEARCH";
		else if(cmd == "EXIT")
			exit(0);
	}
	else
		std::cout << "Please, enter one option: ADD, SEARCH or EXIT";
	std::cout << std::endl;
	return(0);
}