/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:14:56 by lginer-m          #+#    #+#             */
/*   Updated: 2025/12/13 22:00:58 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		std::string cmd = argv[1];
		if(cmd == "ADD")
			std::cout << "ADD";
		else if(cmd == "SEARCH")
			std::cout << "SEARCH";
		else if(cmd == "EXIT")
			exit(0);
	}
	else
		std::cout << "Please, enter one option: ADD, SEARCH or EXIT";
	std::cout << std::endl;
	return(0);
}