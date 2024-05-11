/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PsortMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:26:51 by craimond          #+#    #+#             */
/*   Updated: 2024/05/09 18:23:59 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <exception>
# include <algorithm>
# include <iterator>
# include <vector>
# include <cstddef>

# define K 5

template <typename Container>
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(Container const &container);
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe	&operator=(PmergeMe const &rhs);
		void		feed(Container const &container);
		void		sort();
		Container	&getContainer(void);
	private:
		Container	_container;
};

# include "PmergeMe.tpp"

#endif