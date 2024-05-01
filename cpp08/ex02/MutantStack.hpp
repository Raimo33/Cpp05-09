/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:46:25 by craimond          #+#    #+#             */
/*   Updated: 2024/05/01 11:02:04 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

//uno stack non e' un container, e' un container adapter: gli puoi specificare quale container deve usare dietro le quinte (default deque, altrimenti list, vector, ecc)
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator; //non essendo un typedef statico, non posso usarlo all'interno della definizione della classe stessa

		MutantStack();
		MutantStack(const MutantStack &copy);
		~MutantStack();
		MutantStack &operator=(const MutantStack &rhs);
		iterator begin();
		iterator end();
};

# include "MutantStack.tpp"

#endif