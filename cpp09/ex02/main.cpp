/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:26:45 by craimond          #+#    #+#             */
/*   Updated: 2024/05/10 19:01:24 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO aggiungere il padding

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
template <typename Container>
static void		print_container(const Container &container);
static void		sort(size_t &vec_time, size_t &list_time, PmergeMe<std::deque<int> > &vec_sorter, PmergeMe<std::list<int> > &list_sorter);
static void		print_times(const size_t deque_time, const size_t list_time, const int n_numbers);

int main(const int argc, const char **argv)
{	
	std::deque<int>				deque;
	std::list<int>				list;
	PmergeMe<std::deque<int> >	deque_sorter;
	PmergeMe<std::list<int> >	list_sorter;
	size_t						deque_time;
	size_t						list_time;

	try
	{
		if (check_args(argc, argv) == -1)
			return 1;
		fill_containers(deque, list, argc - 1, argv + 1);
		std::cout << std::setw(5) << "Before: ";
		print_container(deque);
		deque_sorter.feed(deque);
		list_sorter.feed(list);
		sort(deque_time, list_time, deque_sorter, list_sorter);
		deque = deque_sorter.getContainer();
		list = list_sorter.getContainer();
		std::cout << std::setw(5) << "After: ";
		print_container(deque);
		print_times(deque_time, list_time, argc - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
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

template <typename Container>
static void print_container(const Container &container)
{
	for (typename Container::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
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
	vec_time = (end_time - start_time) * 1000000 / CLOCKS_PER_SEC;
	//get list time
	start_time = end_time;
	list_sorter.sort();
	end_time = std::clock();
	list_time = (end_time - start_time) * 1000000 / CLOCKS_PER_SEC;
}

static void print_times(const size_t deque_time, const size_t list_time, const int n_numbers)
{
    std::ostringstream	base_msg;
    base_msg << "Time to process a range of " << n_numbers << " elements with std::";

    std::string base_str = base_msg.str();

    std::cout << std::setw(40) << std::left << base_str + "deque :" 
              << std::setw(5) << std::right << deque_time << " us" << std::endl;

    std::cout << std::setw(40) << std::left << base_str + "list :" 
              << std::setw(5) << std::right << list_time << " us" << std::endl;
}
