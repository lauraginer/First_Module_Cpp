/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:14:56 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/26 01:47:18 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string input;	
	while(1)
	{
		std::cout << "Please, enter one option: ADD, SEARCH or EXIT\n";
		getline(std::cin, input); 
		if(input == "ADD")
			phonebook.addContact();
		else if(input == "SEARCH")
		{
			phonebook.createPhonebook();
			std::cout << "Enter a index for seeing all the information\n"; //retocar esto
		}
		else if(input == "EXIT")
			exit(0);
	}
	//std::cout << std::endl;
	return(0);
}