/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:44:03 by lginer-m          #+#    #+#             */
/*   Updated: 2026/01/21 19:30:07 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::bits = 8; //Bits no se puede modificar por ser const, además de ser comun en TODOS los objetos

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	value = other.value;
}
Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called\n";
	value = number << bits; //Desplazamos el numero de bits(8) a la izq., para establecer la parte decimal
	
	/*Esta operación es lo mismo que value = number * 2^bits (es 256), pero utilizamos el desplazamiento de bits
	porque funciona más rapido para el procesador y es más automatico, menos propenso a errores*/
}
Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called\n";
	value = roundf(number * (1 << bits)); //Roundf redondea al entero más cercano para evitar errores de truncamiento
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
float Fixed::toFloat( void ) const
{
	float real_value;
	
	real_value = static_cast<float>(value) / (1 << bits);
	return(real_value);
}
int Fixed::toInt( void ) const
{
	int real_value;
	
	real_value = value >> bits;
	return(real_value);
}
std::ostream& operator<<(std::ostream& out, Fixed const& obj)
{
	out << obj.toFloat();
    return(out);
}
//Esta funcion necesita que inserte una representación en coma flotante del número de punto fijo en el flujo de salida que se pase como parámetro.