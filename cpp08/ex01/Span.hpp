/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:04 by craimond          #+#    #+#             */
/*   Updated: 2024/04/30 19:22:37 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <cstddef>
# include <vector>

class Span
{
	public:
		Span();
		Span(const size_t N);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &rhs);
		void addNumber(const int n);
		size_t shortestSpan(void) const;
		size_t longestSpan(void) const;
	private:
		std::vector<int>	_numbers;
		std::vector<int>	_sorted_numbers;
		size_t				_size;
};

class NotEnoughElementsException : public std::exception
{
	public:
		virtual const char *what() const throw() //throw() specifica al compiler che la funzione non lancia eccezioni
		{
			return ("Not enough elements to calculate span");
		}
};

#endif