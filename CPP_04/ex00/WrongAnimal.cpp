/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:51:38 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/06 19:18:42 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "Default constructor of WrongAnimal called\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type)
{
	std::cout << "Copy constructor of WrongAnimal called\n";	
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) 
{
	std::cout << "Copy assignment operator of WrongAnimal called\n";
	if(this != &other)
		type = other.type;
	return(*this);
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal called\n";
}
std::string WrongAnimal::getType() const
{
	return(type);
}
void WrongAnimal::makeSound() const
{
	std::cout << "Wronganimal: GrrrrrGrrrrrGrGrrr....\n";
}
