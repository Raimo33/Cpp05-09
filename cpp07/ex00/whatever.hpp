/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:51:05 by craimond          #+#    #+#             */
/*   Updated: 2024/04/29 15:17:23 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T	min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

template <typename T>
T	max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

#endif