/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:29:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/16 16:37:33 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA{
private:
	std::string name;
	Weapon& weapon;
	
public:
	HumanA(std::string name, Weapon& weapon); //Constructor, weapon es obligatorio por subject
	void	attack();
};

#endif