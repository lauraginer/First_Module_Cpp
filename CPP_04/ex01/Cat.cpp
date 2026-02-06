/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:24:04 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/06 21:16:33 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(): Animal()
{
	type = "Cat";
	new Brain();
	std::cout << "Default constructor of Cat called\n";
}
Cat::Cat(const Cat& other): Animal(other)
{
	brain = new Brain(*other.brain); //Deep copy
	std::cout << "Copy constructor of Cat called\n";	
}
Cat& Cat::operator=(const Cat& other) 
{
	std::cout << "Copy assignment operator of Cat called\n";
	if(this != &other)
	{
		Animal::operator=(other);
		delete brain; // Liberamos el Brain antiguo
		brain = new Brain(*other.brain);
	}
	return(*this);
}
Cat::~Cat()
{
	std::cout << "Destructor of Cat called\n";
	delete brain;
}
void Cat::makeSound() const
{
	std::cout << "Cat: Miaaaaauuuuuuu.. RrRrRrRrRrRrRr\n";
}