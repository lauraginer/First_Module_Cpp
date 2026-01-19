/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:30:02 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/16 17:43:07 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon{
private:
	std::string type;
	
public:
	Weapon(std::string const initial_type); //Constructor con parametro
	void	setType(std::string const new_type);
	const std::string &getType() const;
};

#endif