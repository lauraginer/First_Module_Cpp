/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:36:14 by lginer-m          #+#    #+#             */
/*   Updated: 2026/01/09 19:56:08 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i = 1;
	int j;
	char result;
	
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while(i < argc)
		{
			j = 0;
			while(argv[i][j])
			{
				result = toupper(argv[i][j]);
				std::cout << result;
				j++;
			}	
			i++;
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return(0);
}
