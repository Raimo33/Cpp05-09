/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:26:45 by craimond          #+#    #+#             */
/*   Updated: 2024/05/09 18:28:31 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>
#include <stdint.h>

static int8_t check_args(int argc, char **argv);
static void	sort(size_t &vec_time, size_t &list_time, Sorter<std::vector<int>> &vec_sorter, Sorter<std::list<int>> &list_sorter);

int main(int argc, char **argv)
{	
	std::vector<int>			vector;
	std::list<int>				list;
	Sorter<std::vector<int>>	vec_sorter(vector);
	Sorter<std::list<int>>		list_sorter(list);
	size_t						vec_time;
	size_t						list_time;

	if (check_args(argc, argv) == -1)
		return 1;
	fill_containers(vector, list);
	print_before_sort(vector);
	vec_sorter.feed(vector);
	list_sorter.feed(list);
	sort(vec_time, list_time, vec_sorter, list_sorter);
	print_after_sort(vector);
	print_times(vec_time, list_time);
	return 0;
}

static void	sort(size_t &vec_time, size_t &list_time, Sorter<std::vector<int>> &vec_sorter, Sorter<std::list<int>> &list_sorter)
{
	size_t	start_time;
	size_t	end_time;
	
	//get vector time
	start_time = std::clock(); 
	vec_sorter.sort();
	end_time = std::clock();
	vec_time = end_time - start_time;
	//get list time
	start_time = end_time;
	list_sorter.sort();
	end_time = std::clock();
	list_time = end_time - start_time;
}

static int8_t check_args(int argc, char **argv)
{
	if (argc != 1)
	{
		std::cerr << "Usage: ./PmergeMe" << std::endl;
		return -1;
	}
	return 0;
}