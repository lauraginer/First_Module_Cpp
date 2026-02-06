/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:58:29 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/06 21:06:49 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal{
protected:
	std::string type;
	
public:
	Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual~Animal();

	virtual void makeSound() const; 
	std::string getType() const;
};

#endif