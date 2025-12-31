/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:40:41 by lauragm           #+#    #+#             */
/*   Updated: 2025/12/31 15:39:10 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	// Validar número de argumentos
	if (argc == 4)
	{
		std::string filename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
	
		if (filename.empty() || s1.empty() || s2.empty())
		{
			std::cout << "Error: arguments can't be empty!\n";
			return (1);
		}
		
		const char* file_path = filename.c_str(); //convertirmos el argv en char
		std::ifstream infile(file_path); // Abrir archivo de entrada, infile es un objeto
		if (!infile.is_open())
		{
			std::cout << "Error: could not open file " << filename << std::endl;
			return (1);
		}
		
		std::string replace_filename = filename + ".replace"; // Crear nombre del archivo de salida
		std::ofstream outfile(replace_filename.c_str()); // Crear archivo de salida
		if (!outfile.is_open())
		{
			std::cout << "Error: could not create output file" << std::endl;
			infile.close();
			return (1);
		}
		
		//Aquí va la lógica de lectura y reemplazo, leer línea por línea, busca s1, reemplaza por s2, escribe en outfile
		infile.close(); //necesitamos cerrar despues de abrir outfile
		outfile.close();
	}
	else
	{
		std::cout << "Incorrect arguments\n";
		return (1);
	}
	return (0);
}