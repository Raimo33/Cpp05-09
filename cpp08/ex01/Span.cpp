/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:46:38 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 15:12:10 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() :
	_numbers(),
	_sorted_numbers(),
	_capacity(_numbers.max_size()),
	_current_size(0) {}

Span::Span(const size_t N) :
	 _numbers(),
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

void Span::addNumbers(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
	size_t	n_new_elems = std::distance(begin, end);

	if (_current_size + n_new_elems > _capacity)
		throw SpanIsFullException();
	_numbers.insert(_numbers.end(), begin, end);
	_sorted_numbers.insert(begin, end);
	_current_size += n_new_elems;
}

size_t Span::shortestSpan(void) const
{
	if (_current_size < 2)
		throw NotEnoughElementsException();

	int	shortest_span = std::numeric_limits<int>::max();
	std::set<int>::iterator it = _sorted_numbers.begin();
	std::set<int>::iterator it_next = it;

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

void Span::print(void)
{
	std::vector<int>::iterator it = _numbers.begin();

	std::cout << "[ ";
	while (it != _numbers.end() - 1)
	{
		std::cout << *it << ", ";
		it++;
	}
	std::cout << *it << " ]" << std::endl;
}

const char* Span::NotEnoughElementsException::what() const throw()
{
	return "Error: not enough elements";
}

const char* Span::SpanIsFullException::what() const throw()
{
	return "Error: span is full";
}
