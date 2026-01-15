/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:01:34 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/15 14:19:34 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ostream>
#include <iostream>

int main()
{
	std::string original = "HI THIS IS BRAIN";
	std::string *stringPTR = &original; //Puntero - almacena la direccion
	std::string &stringREF = original; //Referencia - Es un alias(otro nombre) del original
	
	//--Direcciones de memorias--
	std::cout << "Memory address of original: " << &original << std::endl;
	std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address of sttringREF: " << &stringREF << std::endl;
	
	//--Valores--
	std::cout << "Value of original: " << original << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;

	return(0);
}
