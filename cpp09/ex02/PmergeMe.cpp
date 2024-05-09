/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PsortMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:26:48 by craimond          #+#    #+#             */
/*   Updated: 2024/05/09 17:51:02 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Sorter::Sorter() 

Sorter::Sorter(std::vector<int> const &vector, std::list<int> const &list) 

Sorter::Sorter(Sorter const &other) 

Sorter &Sorter::operator=(Sorter const &rhs)
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
		_list = rhs._list;
	}
	return (*this);
}

Sorter::~Sorter() {}



void sort()