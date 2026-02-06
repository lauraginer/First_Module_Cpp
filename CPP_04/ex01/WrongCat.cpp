/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:51:41 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/06 21:35:23 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal()
{
	type = "WrongCat";
	std::cout << "Default constructor of WrongCat called\n";
}
WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << "Copy constructor of WrongCat called\n";	
}
WrongCat& WrongCat::operator=(const WrongCat& other) 
{
	std::cout << "Copy assignment operator of WrongCat called\n";
	if(this != &other)
		WrongAnimal::operator=(other);
	return(*this);
}
WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat called\n";
}
void WrongCat::makeSound() const
{
	std::cout << "Wrongcat: GrrrrrGrrrrrGrGrrr....\n";
}