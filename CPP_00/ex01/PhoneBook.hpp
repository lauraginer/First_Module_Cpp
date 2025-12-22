/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:32:36 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/22 13:00:04 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];   // array fijo
    //int count;             // número de contactos actuales
    //int oldest;            // para saber a quién sobrescribir

public:
	void addContact();
	int createPhonebook();
	void checkEmpty(bool &flag, std::string &input, std::string message);
	void uploadInput(std::string &input, bool &flag); 
	//importante!! pasamos por referencia porque si no se crea una copia de la var automaticamente
};

#endif