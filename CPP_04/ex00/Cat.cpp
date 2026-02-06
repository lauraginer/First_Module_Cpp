/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:24:04 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/06 19:00:38 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal()
{
	type = "Cat";
	std::cout << "Default constructor of Cat called\n";
}
Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "Copy constructor of Cat called\n";	
}
Cat& Cat::operator=(const Cat& other) 
{
	std::cout << "Copy assignment operator of Cat called\n";
	if(this != &other)
		type = other.type;
	return(*this);
}
Cat::~Cat()
{
	std::cout << "Destructor of Cat called\n";
}
void Cat::makeSound() const
{
	std::cout << "Cat: Miaaaaauuuuuuu.. RrRrRrRrRrRrRr\n";
}