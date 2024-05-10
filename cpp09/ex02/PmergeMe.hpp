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

# define K 5 //ogni cella avra' K elementi

template <typename Container>
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(Container const &container);
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &rhs);
		void	feed(Container const &container);
		void	sort();
	private:
		Container	_container;
};

class NotANumberException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Error: not a number";
		}
};

#endif