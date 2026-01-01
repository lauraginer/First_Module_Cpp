/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:44:39 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/01 19:44:54 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Test 1: Básico
echo "hello world hello" > test.txt
./replace test.txt hello bye
cat test.txt.replace  // Debe mostrar: "bye world bye"

// Test 2: Sin ocurrencias
echo "foo bar" > test2.txt
./replace test2.txt hello bye
cat test2.txt.replace  // Debe mostrar: "foo bar"

// Test 3: Múltiples líneas
echo -e "hello\nhello world\nhello" > test3.txt
./replace test3.txt hello bye

// Test 4: s1 más largo que s2
./replace test.txt hello hi

// Test 5: s2 más largo que s1
./replace test.txt hi hello

// Test 6: Archivo no existe
./replace noexiste.txt a b  // Error

// Test 7: Argumentos vacíos
./replace "" a b  // Error
./replace test.txt "" b  // Error