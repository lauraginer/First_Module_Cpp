/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:48:56 by lginer-m          #+#    #+#             */
/*   Updated: 2026/01/23 18:56:20 by lginer-m         ###   ########.fr       */
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

//Funciones de sobrecarga de operadores
std::ostream &operator<<(std::ostream& out, Fixed const& obj)
{
	out << obj.toFloat();
    return(out);
}
bool Fixed::operator<(Fixed const& obj) const
{
	bool flag;
	flag = this->value < obj.value;
	return(flag);
}
bool Fixed::operator>(Fixed const& obj) const
{
	bool flag;
	flag = this->value > obj.value;
	return(flag);
}
bool Fixed::operator<=(Fixed const& obj) const
{
	bool flag;
	flag = this->value <= obj.value;
	return(flag);
}
bool Fixed::operator>=(Fixed const& obj) const
{
	bool flag;
	flag = this->value >= obj.value;
	return(flag);
}
bool Fixed::operator==(Fixed const& obj) const
{
	bool flag;
	flag = this->value == obj.value;
	return(flag);
}
bool Fixed::operator!=(Fixed const& obj) const
{
	bool flag;
	flag = this->value != obj.value;
	return(flag);
}

//Funciones aritmeticas
Fixed Fixed::operator+(Fixed const& obj) const
{
	Fixed result;
	result.value = this->value + obj.value;
	return(result);
}
Fixed Fixed::operator-(Fixed const& obj) const
{
	Fixed result;
	result.value = this->value - obj.value;
	return(result);
}
Fixed Fixed::operator*(Fixed const& obj) const //Se puede convertir todas estas funiones aritmeticas a flost,
{											 //Al parecer hay que desplazar los bits para evitar numeros desbordados (sino se multiplican dos veces)
	Fixed result;
	result.value = (this->value * obj.value) >> bits;
	return(result);
}
Fixed Fixed::operator/(Fixed const& obj) const
{
	Fixed result;
	result.value = (this->value << bits) / obj.value;
	return(result);
}

//Funciones de decremento/incremento
Fixed& Fixed::operator++()
{
	this->value++;
	return(*this);
}
Fixed Fixed::operator++(int)
{
	Fixed current_value(*this); //Copia todo el objeto
	this->value++;
	return(current_value);
}
Fixed Fixed::operator--(int)
{
	Fixed current_value(*this); //Copia todo el objeto
	this->value--;
	return(current_value);
}
Fixed& Fixed::operator--()
{
	this->value--;
	return(*this);
}

static Fixed& min(Fixed& a, Fixed& b)
{
	//Devuelve una referencia al menor
	
}