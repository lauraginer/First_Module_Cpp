/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:30:10 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/08 14:12:41 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal{
private:
	Brain *brain;
public:
	Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

	void makeSound() const;
	Brain* getBrain() const;
};

#endif