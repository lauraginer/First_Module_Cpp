/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:32:36 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/26 22:50:00 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];   // array fijo
    int count;             // número de contactos actuales
    int index;            // para saber a quién sobrescribir
    int totalContacts;    // contador real de contactos añadidos

public:
	PhoneBook();  // Constructor(inicializa las variables)
	void addContact();
	int createPhonebook();
	void checkEmpty(std::string &input, std::string message);
	int parseNumber(std::string &phone);
	void saveContact(Contact contact);
	std::string truncateField(std::string field);
	int enterIndex(std::string input);
	//importante!! pasamos por referencia porque si no se crea una copia de la var automaticamente
};

#endif