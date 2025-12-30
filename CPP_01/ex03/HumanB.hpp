/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:29:37 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/30 23:50:23 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "HumanA.hpp"
#include <string>

class HumanB{
private:
	std::string name;
	Weapon* weapon;
	
public:
	HumanB(std::string name);
	void	setWeapon(Weapon& arm);
	void	attack();
};

#endif