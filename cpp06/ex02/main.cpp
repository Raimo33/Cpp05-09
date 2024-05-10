/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:14:46 by craimond          #+#    #+#             */
/*   Updated: 2024/05/10 19:19:03 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib> //for rand() and srand()

void identify(Base* p);
void identify(Base& p);
Base *generate(void);

int main(void)
{
	Base *obj;

	srand(time(NULL));
	obj = generate();
	identify(obj);
	identify(*obj);
	delete obj;
}

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	std::cout << "Object type: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else //if all 3 casts fail, the object is of unknown type (an error occured)
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		identify(&p);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
