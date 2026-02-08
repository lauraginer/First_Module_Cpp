/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:07:26 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/08 17:21:49 by lginer-m         ###   ########.fr       */
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
	std::cout << "--TESTING WITH DIFFERENT OPTIONS--\n";
    const Animal* Doge = new Dog();
    const Animal* Lili = new Cat();
	Dog Tom;
	Cat Mini;
	Doge->makeSound();
	Lili->makeSound();
	Tom.makeSound();
	Mini.makeSound();
    delete Doge; // no debe crear memory leak
    delete Lili;
	std::cout << std::endl;
	std::cout << "--TEST: ANIMAL IS ABSTRACT (SHOULD NOT COMPILE)--\n";
    //Animal* impossible = new Animal();
	//Animal Mouse;	
	//Animal Micky(Mouse);
    std::cout << "Animal cannot be instantiated (it's abstract)\n";
	

    return 0;
}