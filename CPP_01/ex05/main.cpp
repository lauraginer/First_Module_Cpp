/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:27:07 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/02 00:10:09 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl harl;
	
	if(argc == 2)
		harl.complain(argv[1]);
	else
	{
		std::cout << "Error: You need a second input!\n";
		return(1);
	}
	return(0);
}

