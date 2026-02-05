/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:09:12 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/05 17:42:21 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string nick): ClapTrap(nick + "_clap_name"), FragTrap(nick), ScavTrap(nick), name(nick)
{
	hit_points = 100; 	//FragTrap
	energy_points = 50; //ScavTrap
	attack_damage = 30; //FragTrap
	std::cout << "Default constructor of DiamondTrap called\n";
}
DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout << "Copy constructor of DiamondTrap called\n";
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "Copy assignment operator of DiamondTrap called\n";
	if(this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		name = other.name;
	}
	return (*this);
} 
DiamondTrap::~DiamondTrap() // Destructor
{
	std::cout << "Destructor of DiamondTrap called\n";
}
void DiamondTrap::whoAmI()
{
	std::cout << "WHOAMI: DiamondTrap" << " " << name << " " << "and Claptrap " << ClapTrap::name << " " << "exist!";
	std::cout << std::endl;
}