/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:18:39 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/02 17:33:32 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): name(""), hit_points(10), energy_points(10), attack_damage(0) // Constructor por defecto
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
void attack(const std::string& target); 
//Cuando se ataca, hace que su objetivo pierda tantos puntos de vida
//como indica amount

//Ejemplo de salida: ClapTrap <name> attacks <target>, causing <damage> points of damage!

void takeDamage(unsigned int amount);

void beRepaired(unsigned int amount);
//Cuando se recupera, recupera tantos puntos de vida como indica amount