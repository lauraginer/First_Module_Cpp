/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:30:51 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/06 19:00:46 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal()
{
	type = "Dog";
	std::cout << "Default constructor of Dog called\n";
}
Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "Copy constructor of Dog called\n";	
}
Dog& Dog::operator=(const Dog& other) 
{
	std::cout << "Copy assignment operator of Dog called\n";
	if(this != &other)
		type = other.type;
	return(*this);
}
Dog::~Dog()
{
	std::cout << "Destructor of Dog called\n";
}
void Dog::makeSound() const
{
	std::cout << "Dog: GuauGuauGuauuuGuau\n";
}