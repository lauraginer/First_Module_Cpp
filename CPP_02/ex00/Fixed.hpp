/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:44:00 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/02 12:37:13 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>

class Fixed{
private:
	int value; //Almacena el valor del número de punto fijo
	static const int  bits; //Almacena el número de bits fraccionarios
	
public:
	Fixed();                               // Constructor por defecto
    Fixed(const Fixed& other);            // Constructor de copia
    Fixed& operator=(const Fixed& other); // Operador =
    ~Fixed();                             // Destructor
	int getRawBits( void ) const;    // Devuelve el valor interno “en bruto” del número de punto fijo.
	void setRawBits( int const raw ); // Establece directamente ese valor interno.

};

#endif