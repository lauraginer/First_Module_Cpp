/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:07:26 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/06 22:17:22 by lginer-m         ###   ########.fr       */
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
	Animal* animals[size] = {NULL}; // Array de punteros de animal
	
	while(i < size / 2)
	{
		animals[i] = new Cat();
		i++;
	}
	i = size / 2;
	while(i < size)
	{
		animals[i] = new Dog();
		i++;
	}
	while(animals[j])
		delete animals[j++];
	
    const Animal* Doge = new Dog();
    const Animal* Lili = new Cat();
    delete Doge; // no debe crear memory leak
    delete Lili;
    return 0;
}