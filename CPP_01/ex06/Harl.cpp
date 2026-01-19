/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:27:11 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/16 19:19:48 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <ostream>
#include <iostream>

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int index_levels = -1;  //Inicializado en -1 para en caso de error
	int i = 0;
	
	while(i < 4)
	{
		if(levels[i] == level)
		{
			index_levels = i;
			break;
		}
		i++;
	}
	switch(index_levels) //Switch no acepta strings, pero si int entre otros
	{
		case 0:
		{
			std::cout << "[ DEBUG ]\n";
			(this->*functions[0])();
		}
		// fall through
		case 1:
		{
			std::cout << "[ INFO ]\n";
			(this->*functions[1])();
		}
		// fall through
		case 2:
		{
			std::cout << "[ WARNING ]\n";
			(this->*functions[2])();
		}
		// fall through
		case 3:
		{
			std::cout << "[ ERROR ]\n";
			(this->*functions[3])();
		}
		break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
