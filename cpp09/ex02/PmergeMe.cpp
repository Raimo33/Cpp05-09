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
#include "fordJhonsonSort.hpp"

PmergeMe::PmergeMe() : _container() {}

template <typename Container>
PmergeMe::PmergeMe(Container const &container) : _container(container) {}

PmergeMe::PmergeMe(PmergeMe const &other) : _container(other._container) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
		_container = rhs._container;
	return *this;
}

template <typename Container>
void PmergeMe::feed(Container const &container)
{
	_container = container;
}

void PmergeMe::sort()
{
	if (_container.empty())
		return;
	fordJhonsonSort(_container.begin(), _container.end());
}
