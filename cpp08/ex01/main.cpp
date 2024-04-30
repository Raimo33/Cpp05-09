/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:44:58 by craimond          #+#    #+#             */
/*   Updated: 2024/05/01 00:19:07 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"
// #include <cstdlib>

int main()
{
	// Span sp;
	Span				sp(13);
	std::vector<int>	to_add;

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		to_add.push_back(rand() % 100);
	try
	{
		sp.addNumber(6);
		sp.addNumber(9);
		sp.addNumber(15);
		sp.addNumbers(to_add.begin(), to_add.end());
		std::cout << "span: " << std::endl;
		sp.print();
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}