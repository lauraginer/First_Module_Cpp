/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:32:36 by lginer-m          #+#    #+#             */
/*   Updated: 2026/01/09 19:43:53 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

class PhoneBook {
private:
    Contact contacts[8];   // array fijo
    int count;             // número de contactos actuales
    int index;            // para saber a quién sobrescribir

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