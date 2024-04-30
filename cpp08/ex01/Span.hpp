/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:04 by craimond          #+#    #+#             */
/*   Updated: 2024/04/30 23:38:18 by craimond         ###   ########.fr       */
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
	std::vector<int> _numbers;
	std::set<int> _sorted_numbers; // più veloce di std::vector l'inserimento del nuovo numero nella posizione giusta (Red-Black Tree)
	size_t _capacity;
	size_t _current_size;
};

class CustomException : public std::exception
{
	public:
		explicit CustomException(const std::string &message) : _message(message) {}
		virtual ~CustomException() throw() {}
		virtual const char *what() const throw()
		{
			return (_message.c_str());
		}
	protected:
		std::string _message;
};

class NotEnoughElementsException : public CustomException
{
	public:
		NotEnoughElementsException() : CustomException("Not enough elements to calculate span") {}
};

class SpanIsFullException : public CustomException
{
	public:
		SpanIsFullException() : CustomException("Span is full: max capacity reached") {}
};

#endif