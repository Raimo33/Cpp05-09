/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:26:45 by craimond          #+#    #+#             */
/*   Updated: 2024/05/10 17:18:09 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>
#include <stdint.h>
#include <deque>
#include <list>
#include <iomanip>
#include <sstream>

static int8_t	check_args(const int argc, const char **argv);
static void		fill_containers(std::deque<int> &deque, std::list<int> &list, const int n_numbers, const char **numbers);
static void		print_before_sort(std::deque<int> &deque);
static void		sort(size_t &vec_time, size_t &list_time, PmergeMe<std::deque<int> > &vec_sorter, PmergeMe<std::list<int> > &list_sorter);
static void		print_after_sort(std::deque<int> deque);
static void		print_times(const size_t deque_time, const size_t list_time, const int n_numbers);

int main(const int argc, const char **argv)
{	
	std::deque<int>				deque;
	std::list<int>				list;
	PmergeMe<std::deque<int> >	deque_sorter(deque);
	PmergeMe<std::list<int> >	list_sorter(list);
	size_t						deque_time;
	size_t						list_time;

	if (check_args(argc, argv) == -1)
		return 1;
	fill_containers(deque, list, argc - 1, argv);
	print_before_sort(deque);
	deque_sorter.feed(deque);
	list_sorter.feed(list);
	sort(deque_time, list_time, deque_sorter, list_sorter);
	print_after_sort(deque);
	print_times(deque_time, list_time, argc - 1);
	return 0;
}

static int8_t check_args(const int argc, const char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: invalid arguments" << std::endl;
		return -1;
	}
	(void)argv;
	return 0;
}

static void	fill_containers(std::deque<int> &deque, std::list<int> &list, const int n_numbers, const char **numbers)
{
	std::istringstream	iss;
	int					number;

	for (int i = 0; i < n_numbers; i++)
	{
		iss.str(numbers[i]);
		iss >> number;
		if (iss.fail() || !iss.eof())
			throw NotANumberException();
		deque.push_back(number);
		list.push_back(number);
		iss.clear();
	}
}

static void	print_before_sort(std::deque<int> &deque)
{
	std::cout << std::setw(10) << std::left << "Before:";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

static void	sort(size_t &vec_time, size_t &list_time, PmergeMe<std::deque<int> > &vec_sorter, PmergeMe<std::list<int> > &list_sorter)
{
	size_t	start_time;
	size_t	end_time;
	
	//get deque time
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

static void	print_after_sort(std::deque<int> deque)
{
	std::cout << std::setw(10) << std::left << "After:";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

static void print_times(const size_t deque_time, const size_t list_time, const int n_numbers)
{
    std::ostringstream	base_msg;
    base_msg << "Time to process a range of " << n_numbers << " elements with std::";

    std::string base_str = base_msg.str();

    std::cout << std::setw(50) << std::left << base_str + "deque:" 
              << std::setw(10) << std::right << deque_time << " us" << std::endl;

    std::cout << std::setw(50) << std::left << base_str + "list:" 
              << std::setw(10) << std::right << list_time << " us" << std::endl;
}
