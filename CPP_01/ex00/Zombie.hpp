/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:32:40 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/14 20:31:02 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string name;

public:
	Zombie(std::string name); //Constructor
	~Zombie(); //Destructor
	void announce(void);
	
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif