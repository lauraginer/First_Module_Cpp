/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:44:00 by lginer-m          #+#    #+#             */
/*   Updated: 2026/01/13 14:32:06 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
#define Fixed_HPP

#include <string>

class Fixed{
private:
	int value; //almacena el valor del número de punto fijo
	static const int  bits; //almacena el número de bits fraccionarios
	
public:
	Fixed();                               // constructor por defecto
    Fixed(const Fixed& other);            // constructor de copia
    Fixed& operator=(const Fixed& other); // operador =
    ~Fixed();                             // destructor
	int getRawBits( void ) const;    // devuelve el valor interno “en bruto” del número de punto fijo.
	void setRawBits( int const raw ); // establece directamente ese valor interno.

};

#endif