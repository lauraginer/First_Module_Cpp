/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:07:26 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/06 19:47:23 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

int main()
{
	std::cout << std::endl;
	std::cout << "--TEST FROM SUBJECT:--\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	
	std::cout << "--TESTING WRONG CLASES:--\n";
	const WrongAnimal *wan1 = new WrongAnimal();
	const WrongAnimal *wan2 = new WrongCat();
	std::cout << std::endl;
	std::cout << wan1->getType() << " " << std::endl;
	std::cout << wan2->getType() << " " << std::endl;
	wan1->makeSound();
	wan2->makeSound();
	std::cout << std::endl;

	std::cout << "--DIRECT OBJECT TESTS--\n";
	const Cat directCat;
	const WrongCat directWrongCat;
	directCat.makeSound();
	directWrongCat.makeSound();
	std::cout << std::endl;
	
	delete meta;
	delete j;
	delete i;
	delete wan1;
	delete wan2;
	return 0;
}