/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:25:54 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/30 21:34:03 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string		name;

public:
	Zombie();  //constructor
	~Zombie();  //destructor
	void announce(void);
	void setName(std::string nick);
};

// Funciones globales (no son métodos de la clase)
Zombie* zombieHorde( int N, std::string name);


#endif