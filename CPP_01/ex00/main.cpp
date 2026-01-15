/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:47:42 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/15 12:42:09 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *heapZombie;
	Zombie *heapTwoZombie;
	Zombie *heapThreeZombie;
	
	randomChump("Michael");
	randomChump("Robert");
	
	//Zombie en HEAP (newZombie), guardamos el puntero y hacer delete manual
	heapZombie = newZombie("Laura");
	heapTwoZombie = newZombie("Marie");
	heapThreeZombie = newZombie("Frankenstein");
	heapZombie->announce();
	heapTwoZombie->announce();
	heapThreeZombie->announce();
	delete heapZombie;
	delete heapTwoZombie;
	delete heapThreeZombie;
	
	return (0);
}