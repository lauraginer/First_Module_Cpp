/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:07:26 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/08 14:26:33 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

int main()
{
	const int size = 10;
	int i = 0;
	int j = 0;
	Animal* animals[size]; // Array de punteros de animal
	std::cout << std::endl;
	std::cout << "--TEST: FILLING AN ARRAY OF DOGS AND CATS--\n";
	while(i < size / 2)
	{
		animals[i] = new Cat();
		std::cout << "A new kitty!: " << animals[i] << std::endl;
		i++;
	
	}
	std::cout << std::endl;
	while(i < size)
	{
		animals[i] = new Dog();
		std::cout << "A new doggy!: " << animals[i] << std::endl;
		i++;
	}

	std::cout << std::endl;
	std::cout << "--TEST: DELETING ARRAY--\n";
	while(j < size)
		delete animals[j++];
	std::cout << std::endl;
	std::cout << "--TEST FROM SUBJECT--\n";
    const Animal* Doge = new Dog();
    const Animal* Lili = new Cat();
    delete Doge; // no debe crear memory leak
    delete Lili;
	std::cout << std::endl;
	std::cout << "--TEST: DEEP COPY WITH ASSIGNMENT--\n";
    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    std::cout << "cat1 address: " << &cat1 << std::endl;
    std::cout << "cat2 address: " << &cat2 << std::endl;
	std::cout << "cat1 Brain*: " << cat1.getBrain() << std::endl;
	std::cout << "cat2 Brain*: " << cat2.getBrain() << std::endl;
	 std::cout << std::endl;
    std::cout << "--TEST: DEEP COPY WITH COPY CONSTRUCTOR--\n";
    Dog dog1;
    Dog dog2(dog1); // Copy constructor
    std::cout << "dog1 address: " << &dog1 << std::endl;
    std::cout << "dog2 address: " << &dog2 << std::endl;
    std::cout << "dog1 Brain*: " << dog1.getBrain() << std::endl;
    std::cout << "dog2 Brain*: " << dog2.getBrain() << std::endl;
    return 0;
}