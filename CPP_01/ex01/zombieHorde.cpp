/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:55:37 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/15 12:51:01 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	int i = 0;
	
	while(i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return(horde);
}
//Reservar memoria para N objetos Zombie en una única reserva.
//Después, debe inicializar los zombies, dándole a cada uno de ellos el nombre
//pasado como parámetro.
//La función debe devolver un puntero al primer zombie.