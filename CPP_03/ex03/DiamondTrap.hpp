/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:09:20 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/05 13:15:31 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <string>

class DiamondTrap : public FragTrap, public ScavTrap{
private:
	std::string name;
public:
	DiamondTrap(std::string nick);    					// Constructor por defecto
    DiamondTrap(const DiamondTrap& other);            	// Constructor de copia
    DiamondTrap& operator=(const DiamondTrap& other);	// Operador =
    ~DiamondTrap();                             		// Destructor
	using ScavTrap::attack;
	void whoAmI();
};

#endif