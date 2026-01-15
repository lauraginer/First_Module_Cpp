/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:25:54 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/15 12:46:33 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string		name;

public:
	Zombie();  //Constructor
	~Zombie();  //Destructor
	void announce(void);
	void setName(std::string nick);
};

Zombie* zombieHorde( int N, std::string name);

#endif