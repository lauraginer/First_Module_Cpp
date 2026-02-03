/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:18:39 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/03 22:04:33 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string nick): name(nick), hit_points(10), energy_points(10), attack_damage(0) // Constructor por defecto
{
	std::cout << "Default constructor called\n";
}
ClapTrap::ClapTrap(const ClapTrap& other): name(other.name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other.attack_damage) // Constructor de copia
{
	std::cout << "Copy constructor called\n";
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other) // Operador =
{
	std::cout << "Copy assignment operator called\n";
	if(this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	return (*this);
} 
ClapTrap::~ClapTrap() // Destructor
{
	std::cout << "Destructor called\n";
}
void ClapTrap::attack(const std::string& target)
{
	if(energy_points <= 0)
	{
		std::cout << "ClapTrap has not energy!"<< std::endl;
		return;
	}	
	if(hit_points <= 0)
	{
		std::cout << "No! ClapTrap is already dead!"<< std::endl;
		return;

	}
	energy_points--;
	std::cout << "ATTACK: " << "ClapTrap" << " " << name << " " << "attacks" << " " << target << " " << "causing" << " " << attack_damage << " " << "points of damage!" << std::endl;
	//ClapTrap <name> attacks <target>, causing <damage> points of damage!
}
//Cuando se ataca, hace que su objetivo pierda tantos puntos de vida
//como indica amount

void ClapTrap::takeDamage(unsigned int amount)
{
	if(hit_points <= 0)
	{
		std::cout << "No! ClapTrap is already dead!"<< std::endl;
		return;

	}
	if(amount >= hit_points)
        hit_points = 0;
	else
		hit_points = hit_points - amount;
	std::cout << "DAMAGE: " << "ClapTrap" << " " << name << " " << "takes" << " " << amount << " " << "points of damage!" << std::endl;
	if(hit_points == 0)
		std::cout << "No! ClapTrap is already dead!"<< std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(energy_points <= 0)
	{
		std::cout << "ClapTrap has not energy!"<< std::endl;
		return;
	}	
	if(hit_points <= 0)
	{
		std::cout << "No! ClapTrap is already dead!"<< std::endl;
		return;

	}
	energy_points--;
	hit_points = hit_points + amount;
	std::cout << "RECUPERATE: " << "ClapTrap" << " " << name << " " << "recuperates" << " " << amount << " " << "points of life!" << std::endl;
}
