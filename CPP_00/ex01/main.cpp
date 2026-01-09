/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:14:56 by lginer-m          #+#    #+#             */
/*   Updated: 2026/01/09 15:03:32 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

int main()
{
	PhoneBook phonebook;
	std::string input;
	
	while(1)
	{
		std::cout << "Please, enter one option: ADD, SEARCH or EXIT\n";
		std::getline(std::cin, input);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "Detected EOF. Please compile again!\n";
			exit(1);
		}
		if(input == "ADD")
			phonebook.addContact();
		else if(input == "SEARCH")
		{
			if(phonebook.createPhonebook() == 0)
			{
				while(1)
				{
					std::cout << "Enter an index to see all the information: ";
					std::getline(std::cin, input);
					if(std::cin.eof())
					{
						std::cout << std::endl;
						std::cout << "Detected EOF. Please compile again!\n";
						return(1);
					}
					if(input.empty())
					{
						std::cout << "Can't be empty!\n";
						continue;
					}
					if(phonebook.enterIndex(input) == 0)
						break;
				}
			}
		}
		else if(input == "EXIT")
			exit(1);
	}
	return(0);
}