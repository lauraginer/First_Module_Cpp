/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:25:50 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/30 21:10:42 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructor
Zombie::Zombie() : name("name")
{
}

void Zombie::setName(std::string nick)
{
	name = nick;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << name << std::endl;
}

//Los zombies deben ser destruidos cuando ya no se necesiten.
//El destructor de la clase Zombie debe imprimir un mensaje con el nombre del zombie, únicamente con fines de depuración.