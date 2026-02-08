/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:33:10 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/08 14:05:13 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain{
protected:
	std::string ideas[100];
	
public:
	Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    virtual~Brain();
	
	std::string getIdeas() const;
};

#endif