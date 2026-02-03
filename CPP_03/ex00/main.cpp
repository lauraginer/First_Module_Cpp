/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:18:30 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/03 21:22:05 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Clap1("Ana");
	ClapTrap Clap2("Luis");
	ClapTrap Clap3("Pablo");
	int i = 0;
	
	//Ana ataca a Luis
	Clap1.attack("Luis");
	Clap2.takeDamage(3);
	Clap2.beRepaired(2);

	//Luis ataca a Pablo
	Clap2.attack("Pablo");
	Clap3.takeDamage(0);
	Clap3.beRepaired(0);
	
	//Atacar sin energía (11 veces)
	while(i < 11)
	{
		Clap2.attack("Pablo");
		i++;
	}
	
	//Recuperar sin vida
	Clap3.takeDamage(15);
    Clap3.beRepaired(5); 
	
}

//Hay que controlar los putos numeros negativos, superiores a unsigned int no compia directamente