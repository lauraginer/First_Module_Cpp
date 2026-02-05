/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:45:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/02/05 12:52:36 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp" 

#include <string>

class FragTrap : public virtual ClapTrap{
public:
	FragTrap(std::string nick);    				// Constructor por defecto
    FragTrap(const FragTrap& other);            // Constructor de copia
    FragTrap& operator=(const FragTrap& other);	// Operador =
    ~FragTrap();                             	// Destructor
	void highFivesGuys(void);
};

#endif