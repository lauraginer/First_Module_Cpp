/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:29:37 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/16 16:38:37 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB{
private:
	std::string name;
	Weapon* weapon;
	
public:
	HumanB(std::string name); //Constructor, weapon no es obligatorio por subject
	void	setWeapon(Weapon& arm);
	void	attack();
};

#endif