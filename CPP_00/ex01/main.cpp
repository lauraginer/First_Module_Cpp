/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:14:56 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/22 13:05:46 by lginer-m         ###   ########.fr       */
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
		{ 
			phonebook.addContact();
			//phonebook.createPhonebook();
		}
		else if(input == "SEARCH")
			std::cout << "SEARCH\n";
		else if(input == "EXIT")
			exit(0);
	}
	//std::cout << std::endl;
	return(0);
}