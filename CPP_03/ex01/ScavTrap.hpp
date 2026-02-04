/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:05:49 by lauragm           #+#    #+#             */
/*   Updated: 2026/02/04 21:43:21 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp" 
#include <string>

class ScavTrap : public ClapTrap{
public:
	ScavTrap(std::string nick);    // Constructor por defecto
    ScavTrap(const ScavTrap& other);            // Constructor de copia
    ScavTrap& operator=(const ScavTrap& other);	// Operador =
    ~ScavTrap();                             	// Destructor
	void attack(const std::string& target);
	void guardGate();
};

#endif