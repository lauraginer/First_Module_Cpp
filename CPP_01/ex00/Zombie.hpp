/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:32:40 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/28 21:39:40 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string		name;

public:
	Zombie(std::string name);  //constructor
	~Zombie();  //destructor
	void announce(void);
	
};

// Funciones globales (no son métodos de la clase)
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif