/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:17:03 by craimond          #+#    #+#             */
/*   Updated: 2024/04/29 19:44:02 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib> //rand

int main(void)
{
	Array<int>			intArray(5);
	Array<int>			intArray2(5);
	Array<char>			charArray(6);
	Array<float>		floatArray(4);
	Array<double>		doubleArray(3);
	Array<std::string>	stringArray(2);
	Array< Array<int> >	arrayArray(2);

	srand(time(NULL));

	for (size_t i = 0; i < intArray.size(); i++)
		intArray[i] = rand() % 100;
	
	for (size_t i = 0; i < intArray2.size(); i++)
		intArray2[i] = rand() % 100;

	for (size_t i = 0; i < charArray.size(); i++)
		charArray[i] = rand() % 26 + 'a';

	for (size_t i = 0; i < floatArray.size(); i++)
		floatArray[i] = (float)(rand() % 100) / 9.81f;
	
	for (size_t i = 0; i < doubleArray.size(); i++)
		doubleArray[i] = (double)(rand() % 100) / 9.80665;

	stringArray[0] = "Hello";
	stringArray[1] = "World";

	arrayArray[0] = intArray;
	arrayArray[1] = intArray2;

	std::cout << "Int array: " << intArray << std::endl;
	std::cout << "Char array: " << charArray << std::endl;
	std::cout << "Float array: " << floatArray << std::endl;
	std::cout << "Double array: " << doubleArray << std::endl;
	std::cout << "String array: " << stringArray << std::endl;
	std::cout << "Array array: " << arrayArray << std::endl;
}
