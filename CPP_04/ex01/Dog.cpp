/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:30:51 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/06 21:35:01 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(): Animal()
{
	type = "Dog";
	new Brain();
	std::cout << "Default constructor of Dog called\n";
}
Dog::Dog(const Dog& other): Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Copy constructor of Dog called\n";	
}
Dog& Dog::operator=(const Dog& other) 
{
	std::cout << "Copy assignment operator of Dog called\n";
	if(this != &other)
	{
		Animal::operator=(other);
		delete brain; // Liberamos el Brain antiguo
		brain = new Brain(*other.brain);
	}
	return(*this);
}
Dog::~Dog()
{
	delete brain;
	std::cout << "Destructor of Dog called\n";
}
void Dog::makeSound() const
{
	std::cout << "Dog: GuauGuauGuauuuGuau\n";
}