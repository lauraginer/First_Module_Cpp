/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:23:49 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/30 21:34:58 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *hordezombie;
	int N;
	int i = 0;
	
	N = 3;
	hordezombie = zombieHorde(N, "Jose");
	while(i < N)
	{
		hordezombie[i].announce();  //Llamar al método desde el objeto
		i++;
	}
	delete[] hordezombie;
	return(0);
}