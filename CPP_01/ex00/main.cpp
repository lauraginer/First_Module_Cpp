/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:47:42 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/28 21:24:32 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* heapZombie;
	Zombie* heapTwoZombie;
	Zombie* heapThreeZombie;
	
	randomChump("Michael");
	randomChump("Robert");
	//Zombie en HEAP (newZombie), guardamos el puntero y hacer delete manual
	heapZombie = newZombie("Laura");
	heapTwoZombie = newZombie("Marie");
	heapThreeZombie = newZombie("Frankenstein");
	heapZombie->announce();
	heapTwoZombie->announce();
	heapThreeZombie->announce();
	delete heapZombie; //despues de delete, se llama al destructor automaticamente
	delete heapTwoZombie;
	delete heapThreeZombie;
	
	return 0;
}