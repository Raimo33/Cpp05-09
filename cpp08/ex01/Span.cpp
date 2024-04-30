/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:46:38 by craimond          #+#    #+#             */
/*   Updated: 2024/04/30 23:40:37 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>

Span::Span() :
	_numbers(),
	_sorted_numbers(),
	_capacity(_numbers.max_size()),
	_current_size(0) {}

Span::Span(const size_t N) :
	 _numbers(N),
	 _sorted_numbers(),
	 _capacity(N),
	 _current_size(0) {}

Span::Span(const Span &other) : 
	_numbers(other._numbers),  // chiamo il copy constructor di std::vector
	_sorted_numbers(other._sorted_numbers),
	_capacity(other._capacity),
	_current_size(other._current_size) {}

Span::~Span(){};

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_numbers = rhs._numbers; // chiamo l'operator overload di std::vector (deep copy)
		_sorted_numbers = rhs._sorted_numbers;
		_capacity = rhs._capacity;
		_current_size = rhs._current_size;
	}
	return (*this);
}

void Span::addNumber(const int n)
{
	if (_current_size >= _capacity)
		throw SpanIsFullException();
	_numbers.push_back(n);
	_sorted_numbers.insert(n);
	_current_size++;
}

size_t Span::shortestSpan(void) const
{
	if (_current_size < 2)
		throw NotEnoughElementsException();

	int	shortest_span = std::numeric_limits<int>::max();
	typename std::set<int>::iterator it = _sorted_numbers.begin();
	typename std::set<int>::iterator it_next = it;

	++it_next;
	while (it_next != _sorted_numbers.end())
	{
		int current_span = *it_next - *it;
		shortest_span = std::min(shortest_span, current_span);
		it++;
		it_next++;
	}
	return (shortest_span);
}

size_t Span::longestSpan(void) const
{
	if (_current_size < 2)
		throw NotEnoughElementsException();

	return (*_sorted_numbers.rbegin() - *_sorted_numbers.begin());
}