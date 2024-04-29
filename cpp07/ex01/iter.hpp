/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:24:56 by craimond          #+#    #+#             */
/*   Updated: 2024/04/29 16:29:18 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <stdint.h>
# include <stddef.h>

template <typename T>
void	iter(const uintptr_t address, const size_t length, void (*f)(T &))
{
	T	*array;

	if (address == 0x0 || length == 0)
		return ;
	array = reinterpret_cast<T *>(address);
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif