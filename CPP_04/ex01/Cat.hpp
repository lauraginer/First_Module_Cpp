/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:21:48 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/08 14:12:50 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal{
private:
	Brain *brain;
	
public:
	Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

	void makeSound() const; 
	Brain* getBrain() const;
};

#endif