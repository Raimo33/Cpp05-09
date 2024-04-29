/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:56:27 by craimond          #+#    #+#             */
/*   Updated: 2024/04/29 13:57:14 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {}

Data::Data(const Data &other)
{
	*this = other;
}

Data::~Data() {}

Data &Data::operator=(const Data &rhs)
{
	(void)rhs;
	return *this;
}