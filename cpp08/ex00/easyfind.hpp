/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:16:08 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 14:06:42 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>

template <typename T>
size_t	easyfind(const T &container, const int target);

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

# include "easyfind.tpp"

#endif