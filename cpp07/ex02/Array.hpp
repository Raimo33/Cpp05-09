/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:14:35 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 14:54:48 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stddef.h>
# include <iostream>

template <typename T>
class Array
{
	public:
		Array();
		Array(const size_t n);
		Array(const Array &other);
		~Array();
		Array	&operator=(const Array &rhs);
		const T	&operator[](const size_t index) const;
		T 		&operator[](const size_t index);
		size_t size(void) const;
	private:
		T		*_array;
		size_t	_size;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array);

# include "Array.tpp"

#endif