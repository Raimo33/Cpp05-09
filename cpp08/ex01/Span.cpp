/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:46:38 by craimond          #+#    #+#             */
/*   Updated: 2024/04/30 19:24:05 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : _numbers(), _sorted_numbers(), _size(0) {};

Span::Span(const size_t N) : _numbers(N), _sorted_numbers(), _size(0) {};

Span::Span(const Span &other) : _numbers(other._numbers), _sorted_numbers(other._sorted_numbers), _size(other._size) {}; //chiamo il copy constructor di std::vector

Span::~Span() {};

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
		_numbers = rhs._numbers; //chiamo l'operator overload di std::vector
	return (*this);
}

void Span::addNumber(const int n)
{
	_numbers.push_back(n);
	_sorted_numbers.push_back(n);
	_size++;
	std::sort(_sorted_numbers.begin(), _sorted_numbers.end());
}

size_t Span::shortestSpan(void) const
{
	if (_numbers.size() < 2)
		throw NotEnoughElementsException();

	int	min = _sorted_numbers[1] - _sorted_numbers[0];
	for (size_t i = 0; i < _size - 1; i++)
	{
		if (_sorted_numbers[i + 1] - _sorted_numbers[i] < min)
			min = _sorted_numbers[i + 1] - _sorted_numbers[i];
	}
	return (min);
}

size_t Span::longestSpan(void) const
{
	if (_numbers.size() < 2)
		throw NotEnoughElementsException();

	return (_sorted_numbers[_size - 1] - _sorted_numbers[0]);
}