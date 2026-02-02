/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:18:33 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/02 17:39:22 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap{
private:
	std::string name; //se pasa como parametro al constructor
	int hit_points; //representan la vida del ClapTrap
	int energy_points;
	int attack_damage;
	
public:
	ClapTrap();                               // Constructor por defecto
    ClapTrap(const ClapTrap& other);            // Constructor de copia
    ClapTrap& operator=(const ClapTrap& other); // Operador =
    ~ClapTrap();                             // Destructor
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif