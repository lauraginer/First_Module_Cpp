/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:32:37 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/28 21:39:30 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructor
Zombie::Zombie(std::string name) : name(name)
{
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