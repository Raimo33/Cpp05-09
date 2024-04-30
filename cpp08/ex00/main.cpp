/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:25:18 by craimond          #+#    #+#             */
/*   Updated: 2024/04/30 15:32:35 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <vector>
#include <list>
#include <deque>
#include <set>

#include "easyfind.hpp"

int main(void)
{
	std::vector<int>	vector;
	std::list<int>		list;
	std::deque<int>		deque;
	std::set<int>		set;

	for (int i = 0; i < 5; i++)
	{
		vector.push_back(i);
		list.push_back(i);
		deque.push_back(i);
		set.insert(i);
	}
 
	try
	{
		int to_find = 6;

		std::cout << "Searching for: '" << to_find << "' in all containers" << std::endl;
		std::cout << "Vector: " << easyfind(vector, to_find) << std::endl; //TODO non funziona
		std::cout << "List: " << easyfind(list, to_find) << std::endl;
		std::cout << "Deque: " << easyfind(deque, to_find) << std::endl;
		std::cout << "Set: " << easyfind(set, to_find) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

