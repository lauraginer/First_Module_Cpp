/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:30:02 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/30 23:36:49 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon{
private:
	std::string type;
	
public:
	Weapon(std::string const initial_type); //constructor con parametro
	void	setType(std::string const new_type);
	const std::string& getType() const;
};

#endif