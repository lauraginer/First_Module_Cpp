/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:29:51 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/30 23:35:19 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

Weapon::Weapon(std::string const initial_type) : type(initial_type){
	
}

void Weapon::setType(std::string const new_type)
{
	type = new_type;
}

const std::string& Weapon::getType() const
{
	return(type);
}
