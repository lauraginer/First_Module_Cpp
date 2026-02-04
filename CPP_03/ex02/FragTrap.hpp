/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:45:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/02/04 22:51:06 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp" 

#include <string>

class FragTrap : public ClapTrap{
public:
	FragTrap(std::string nick);    				// Constructor por defecto
    FragTrap(const FragTrap& other);            // Constructor de copia
    FragTrap& operator=(const FragTrap& other);	// Operador =
    ~FragTrap();                             	// Destructor
	void highFivesGuys(void);
};

#endif