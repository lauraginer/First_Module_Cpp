/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:32:36 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/19 20:06:56 by lginer-m         ###   ########.fr       */
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
  // declaraciones de funciones en teoria
  void addContact();
  int createPhonebook();
  
};

#endif