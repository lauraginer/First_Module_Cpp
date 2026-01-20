/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:44:03 by lginer-m          #+#    #+#             */
/*   Updated: 2026/01/20 16:36:07 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::bits = 8; //Bits no se puede modificar por ser const, además de ser comun en TODOS los objetos

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	value = other.value;
	std::cout << "Copy constructor called\n";
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called \n";
	if(this != &other)  //Protección contra auto-asignación (a = a)
        this->value = other.value;
    return *this;  //Retorna referencia al objeto actual
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return(value);
}
void Fixed::setRawBits( int const raw )
{
		value = raw;
}
