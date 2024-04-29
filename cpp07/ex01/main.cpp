/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:29:45 by craimond          #+#    #+#             */
/*   Updated: 2024/04/29 18:07:00 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	negate(int &a);
void	addOne(int &a);
void	charToUpper(int &c);
void	charToLower(int &c);
void	strToUpper(std::string &str);
void	strToLower(std::string &str);

template <typename T>
void	printArray(T *array, size_t length)
{
	std::cout << "Array: ";
	for (size_t i = 0; i < length; i++)
		std::cout << array[i] << "|";
	std::cout << std::endl;
}

int main(void)
{
	{
		int			array[] = {1, 2, 3, 4, 5};
		uintptr_t	address = reinterpret_cast<uintptr_t>(array);
		size_t		lenght = sizeof(array) / sizeof(array[0]);

		std::cout << "Original array: ";
		printArray(array, lenght);
		::iter(address, lenght, negate);
		std::cout << "Negated array: ";
		printArray(array, lenght);
		::iter(address, lenght, addOne);
		std::cout << "Incremented array: ";
		printArray(array, lenght);
	}
	{
		char		array[] = {'s', 'T', 'r', 'I', 'n', 'g'};
		uintptr_t	address = reinterpret_cast<uintptr_t>(array);
		size_t		lenght = sizeof(array) / sizeof(array[0]);

		std::cout << "Original array: ";
		printArray(array, lenght);
		::iter(address, lenght, charToUpper);
		std::cout << "Uppercased array: ";
		printArray(array, lenght);
		::iter(address, lenght, charToLower);
		std::cout << "Lowercased array: ";
		printArray(array, lenght);
	}
	{
		std::string	array[] = {"string1", "string2", "string3"};
		uintptr_t	address = reinterpret_cast<uintptr_t>(array);
		size_t		lenght = sizeof(array) / sizeof(array[0]);

		std::cout << "Original array: ";
		printArray(array, lenght);
		::iter(address, lenght, strToUpper);
		std::cout << "Uppercased array: ";
		printArray(array, lenght);
		::iter(address, lenght, strToLower);
		std::cout << "Lowercased array: ";
		printArray(array, lenght);
	}
}

void	negate(int &a)
{
	a = -a;
}

void	addOne(int &a)
{
	a++;
}

void	charToUpper(int &c)
{
	c = std::toupper(c);
}

void	charToLower(int &c)
{
	c = std::tolower(c);
}

void	strToUpper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

void	strToLower(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
}
