/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:49:05 by lginer-m          #+#    #+#             */
/*   Updated: 2026/01/26 12:57:27 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
#define Fixed_HPP

#include <string>

class Fixed{
private:
	int value; //Almacena el valor del número de punto fijo
	static const int  bits; //Almacena el número de bits fraccionarios
	
public:
	Fixed();								// Constructor por defecto
	Fixed(const int number);				// Convertimos el entero al valor correspondiente del numero fijo
	Fixed(const float number); 				// Constructor que convierte un número en coma flotante al valor correspondiente del numero fijo
    Fixed(const Fixed& other);            	// Constructor de copia
    Fixed& operator=(const Fixed& other); 	// Operador =
    ~Fixed();                             	// Destructor
	int getRawBits( void ) const;    		// Devuelve el valor interno “en bruto” del número de punto fijo
	void setRawBits( int const raw ); 		// Establece directamente ese valor interno

	float toFloat( void ) const;			//Convierte el valor en punto fijo a un valor de tipo float
	int toInt( void ) const;				//Convierte el valor en punto fijo a un valor de tipo int

	bool operator<(Fixed const& obj) const; //Funcion de sobrecarga del operador <
	bool operator>(Fixed const& obj) const; //Funcion de sobrecarga del operador >
	bool operator<=(Fixed const& obj) const; //Funcion de sobrecarga del operador <=
	bool operator>=(Fixed const& obj) const; //Funcion de sobrecarga del operador >=
	bool operator==(Fixed const& obj) const; //Funcion de sobrecarga del operador ==
	bool operator!=(Fixed const& obj) const; //Funcion de sobrecarga del operador !=

	Fixed operator+(Fixed const& obj) const;  //Funcion del operador aritmetico de +
	Fixed operator-(Fixed const& obj) const;  //Funcion del operador aritmetico de -
	Fixed operator*(Fixed const& obj) const;  //Funcion del operador aritmetico de *
	Fixed operator/(Fixed const& obj) const;  //Funcion del operador aritmetico de /

	Fixed &operator++();    //Funcion del operador aritmetico de ++ preincremento
	Fixed operator++(int);  //Funcion del operador aritmetico de ++ postincremento
	Fixed &operator--();    //Funcion del operador aritmetico de -- predecremento
	Fixed operator--(int);  //Funcion del operador aritmetico de -- postdecremento
	
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);	
};

std::ostream &operator<<(std::ostream& out, Fixed const& obj); //Funcion de sobrecarga del operador <<
#endif