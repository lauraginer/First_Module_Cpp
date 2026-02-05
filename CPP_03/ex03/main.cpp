/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:18:30 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/05 16:57:23 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap Clap1("Ana");
	ClapTrap Clap2("Luis");
	ClapTrap Clap3("Pablo");
	
	ScavTrap Scav1("Mauricio");
	ScavTrap Scav2("Hurraca");

	FragTrap Frag1("Jhon");
	FragTrap Frag2("Tommy");
	std::cout << std::endl;
	int i = 0;

	// Ana ataca a Luis
	std::cout << "--TEST: ANA ATTACKS LUIS--" << std::endl;
	Clap1.attack("Luis");
	Clap2.takeDamage(0);
	Clap2.beRepaired(4);
	std::cout << std::endl;

	// Luis ataca a Pablo
	std::cout << "--TEST: LUIS ATTACKS PABLO--" << std::endl;
	Clap2.attack("Pablo");
	Clap3.takeDamage(0);
	Clap3.beRepaired(0);
	std::cout << std::endl;
	
	// Atacar sin energía (11 veces)
	std::cout << "--TEST: TRYING TO ATTACK WITHOUT ENERGY--" << std::endl;
	while(i < 11)
	{
		Clap2.attack("Pablo");
		i++;
	}
	std::cout << std::endl;
	
	// Recuperar sin vida
	std::cout << "--TEST: TRYING TO RECUPERATE LIFE BEING DEAD--" << std::endl;
	Clap3.takeDamage(15);
    Clap3.beRepaired(5);
	std::cout << std::endl;

	// Test ScavTrap
	std::cout << "--TEST: MAURICIO ATTACKS HURRACA--" << std::endl;
	Scav1.attack("Hurraca");
	Scav2.takeDamage(3);
	Scav2.beRepaired(2);
	Scav2.attack("Mauricio");
	std::cout << std::endl;
	
	// Test funcion guardGate
	std::cout << "--TEST: MAKE GUARDGATE--" << std::endl;
	Scav1.guardGate();
	std::cout << std::endl;

	// Test FragTrap
	std::cout << "--TEST: JHON ATTACKS TOMMY--" << std::endl;
	Frag1.attack("Tommy");
	Frag2.takeDamage(10);
	Frag1.beRepaired(5);
	Frag2.attack("Jhon");
	std::cout << std::endl;

	// Test funcion highFivesGuys
	std::cout << "--TEST: MAKE HIGHFIVESGUYS--" << std::endl;
	Frag1.highFivesGuys();
	std::cout << std::endl;

	// Test de DiamondTrap
	std::cout << "--TEST: MAKING DIAMONDTRAP OBJECTS--" << std::endl;
	DiamondTrap Dmd1("Zipi");
	DiamondTrap Dmd2("Zape");
	std::cout << std::endl;
	std::cout << "--TEST: ZIPI ATTACKS ZAPE--" << std::endl;
	Dmd1.attack("Zape");
	Dmd2.takeDamage(4);
	Dmd1.beRepaired(9);
	std::cout << std::endl;
	std::cout << "--TEST: MAKE WHOIAM--" << std::endl;
	Dmd1.whoAmI();
	Dmd2.whoAmI();
}