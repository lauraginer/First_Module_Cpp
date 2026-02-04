/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:05:23 by lauragm           #+#    #+#             */
/*   Updated: 2026/02/04 21:37:42 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string nick): ClapTrap(nick) // Constructor por defecto
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "Default constructor of ScavTrap called\n";
}
ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) // Constructor de copia
{
	std::cout << "Copy constructor of ScavTrap called\n";
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other) // Operador =
{
	std::cout << "Copy assignment operator of ScavTrap called\n";
	if(this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
} 
ScavTrap::~ScavTrap() // Destructor
{
	std::cout << "Destructor of ScavTrap called\n";
}
void ScavTrap::attack(const std::string& target)
{
	if(energy_points <= 0)
	{
		std::cout << "ScavTrap has not energy!"<< std::endl;
		return;
	}	
	if(hit_points <= 0)
	{
		std::cout << "Oh No! ScavTrap is already dead!"<< std::endl;
		return;

	}
	energy_points--;
	std::cout << "ATTACK: " << "ScavTrap" << " " << name << " " << "attacks" << " " << target << " " << "causing" << " " << attack_damage << " " << "points of damage!" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "GATE KEEPER: ScavTrap is now in Gate keeper mode\n";
}
