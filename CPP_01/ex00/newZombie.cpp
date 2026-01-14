/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:32:28 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/14 20:30:16 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Memoria dinamica para poder usarlo fuera del ámbito de la funcion
Zombie* newZombie(std::string name) 
{
	Zombie* zombie;
	
	zombie = new Zombie(name);
	return zombie;
}
