/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:16:08 by craimond          #+#    #+#             */
/*   Updated: 2024/04/30 13:31:22 by craimond         ###   ########.fr       */
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
		virtual const char* what() const throw()
		{
			return "Element not found";
		}
};

# include "easyfind.tpp"

#endif