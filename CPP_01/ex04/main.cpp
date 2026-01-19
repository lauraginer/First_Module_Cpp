/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:40:41 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/16 18:17:20 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replace(std::ifstream& infile, std::ofstream& outfile, std::string s1, std::string s2)
{
	std::string line;
	while(std::getline(infile, line)) //Leemos linea por linea
	{	
		size_t pos = 0;
		while((pos = line.find(s1, pos)) != std::string::npos) //Necesitamos el bucle para que entre más veces dentro de la misma linea!!
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = pos + s2.length(); //Pos apunta justo despues de s2 ahora
		}
		outfile << line << std::endl;
	}
}

int createFile(std::string filename, std::string s1, std::string s2)
{
	const char* file_path = filename.c_str(); //Convertirmos el argv en char
	std::string replace_filename = filename + ".replace"; //Crear nombre del archivo de salida
	const char *new_file_path = replace_filename.c_str(); //Volvemos a convertir a char
	
	std::ifstream infile(file_path); //Abrir archivo de entrada, infile es un objeto
	if (!infile.is_open())
	{
		std::cout << "Error: could not open file " << filename << std::endl;
		return (1);
	}

	std::ofstream outfile(new_file_path); //Crear archivo de salida
	if (!outfile.is_open())
	{
		std::cout << "Error: could not create output file" << std::endl;
		infile.close();
		return (1);
	}
	replace(infile, outfile, s1, s2);
	infile.close(); //Necesitamos cerrar despues de abrir outfile
	outfile.close();
	return(0);	
}

int main(int argc, char **argv)
{
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
		return(createFile(filename, s1, s2));
	}
	else
	{
		std::cout << "Incorrect arguments\n";
		return (1);
	}
	return (0);
}