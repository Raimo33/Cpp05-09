/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:04 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 15:11:10 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <cstddef>
# include <vector>
# include <set>
# include <string>
# include <algorithm>
# include <limits>
# include <iostream>

class Span
{
	public:
		Span();
		Span(const size_t N);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &rhs);
		void	addNumber(const int n);
		void	addNumbers(const std::vector<int>::iterator begin, const std::vector<int>::iterator end);
		size_t	shortestSpan(void) const;
		size_t	longestSpan(void) const;
		void	print(void);
		class	NotEnoughElementsException;
		class	SpanIsFullException;
	private:
		std::vector<int> 	_numbers;
		std::set<int> 		_sorted_numbers; // più veloce di std::vector l'inserimento del nuovo numero nella posizione giusta (Red-Black Tree)
		size_t 				_capacity;
		size_t 				_current_size;
};

std::ostream &operator<<(const std::ostream &os, const Span &span);

class Span::NotEnoughElementsException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class Span::SpanIsFullException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif