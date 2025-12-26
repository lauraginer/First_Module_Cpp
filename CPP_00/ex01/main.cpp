/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:14:56 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/26 22:19:34 by lauragm          ###   ########.fr       */
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
		std::getline(std::cin, input);
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
			exit(0);
	}
	return(0);
}