/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:59:06 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 14:55:25 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {};

template <typename T>
Array<T>::Array(const size_t n) : _array(new T[n]), _size(n)
{
	//forse non necessario
	for (size_t i = 0; i < _size; i++)
		_array[i] = T();
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	_size = other.size();
	_array = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_array[i] = other[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		delete[] _array;
		_size = rhs.size();
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_array[i] = rhs[i];
	}
	return *this;
}

template <typename T>
const T &Array<T>::operator[](const size_t index) const
{
	if (index >= _size || index < 0)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

template <typename T>
T &Array<T>::operator[](const size_t index)
{
	if (index >= _size || index < 0)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

template <typename T>
size_t Array<T>::size(void) const
{
	return _size;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array)
{
	size_t	length = array.size();

	os << "[ ";
	for (size_t i = 0; i < length - 1; i++)
		os << array[i] << ", ";
	os << array[length - 1] << " ]";
	return os;
}