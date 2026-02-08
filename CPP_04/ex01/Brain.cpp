/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:47:26 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/08 14:05:04 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Default constructor of Brain called\n";
}
Brain::Brain(const Brain& other)
{
	std::cout << "Copy constructor of Brain called\n";
	int i = 0;
	if(this != &other)
	{
		while(i < 100)
		{
			this->ideas[i] = other.ideas[i];
			i++;
		}
	}
}
Brain& Brain::operator=(const Brain& other) 
{
	std::cout << "Copy assignment operator of Brain called\n";
	int i = 0;
	if(this != &other)
	{
		while(i < 100)
		{
			this->ideas[i] = other.ideas[i];
			i++;
		}
	}
	return(*this);
}
Brain::~Brain()
{
	std::cout << "Destructor of Brain called\n";
}
std::string Brain::getIdeas() const
{
	int i = 0;
	if(i > 0 && i < 100)
	{
		return(this->ideas[i]);
	}
	return(NULL);
}
