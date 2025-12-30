/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:29:31 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/30 23:19:21 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA{
private:
	std::string name;
	Weapon& weapon;
	
public:
	HumanA(std::string name, Weapon& weapon); //constructor
	void	attack();
};

#endif