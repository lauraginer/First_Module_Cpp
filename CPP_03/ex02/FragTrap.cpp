/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:45:18 by lauragm           #+#    #+#             */
/*   Updated: 2026/02/04 22:57:54 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string nick): ClapTrap(nick) // Constructor por defecto
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "Default constructor of FragTrap called\n";
}
FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) // Constructor de copia
{
	std::cout << "Copy constructor of FragTrap called\n";
}
FragTrap& FragTrap::operator=(const FragTrap& other) // Operador =
{
	std::cout << "Copy assignment operator of FragTrap called\n";
	if(this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
} 
FragTrap::~FragTrap() // Destructor
{
	std::cout << "Destructor of FragTrap called\n";
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "HIGH FIVES: FragTrap high fives!!\n";
}
