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

# include <vector>
# include <list>
template <typename Container>
class Sorter
{
	public:
		Sorter();
		Sorter(Container const &container);
		Sorter(Sorter const &other);
		~Sorter();
		Sorter &operator=(Sorter const &rhs);
		void	feed(Container const &container);
		void	sort();
	private:
		Container	_container;
};

#endif