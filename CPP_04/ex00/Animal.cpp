/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:09:34 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/06 19:18:32 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type("Animal")
{
	std::cout << "Default constructor of Animal called\n";
}
Animal::Animal(const Animal& other): type(other.type)
{
	std::cout << "Copy constructor of Animal called\n";	
}
Animal& Animal::operator=(const Animal& other) 
{
	std::cout << "Copy assignment operator of Animal called\n";
	if(this != &other)
		type = other.type;
	return(*this);
}
Animal::~Animal()
{
	std::cout << "Destructor of Animal called\n";
}
std::string Animal::getType() const
{
	return(type);
}
void Animal::makeSound() const
{
	std::cout << "Generic animal\n";
}

