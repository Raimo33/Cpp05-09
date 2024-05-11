/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:52:13 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 15:22:29 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <exception>

class RPN
{
	public:
		RPN();
		RPN(RPN const &other);
		~RPN();
		RPN &operator=(RPN const &rhs);
		void	addOperand(const char op);
		void	addNumber(const int n);
		int		getResult(void) const;
		class	invalidOperandException;
		class	stackTooSmallException;
		class	divisionByZeroException;
		class	invalidExpressionException;
	private:
		std::stack<int>	_stack;
};

class RPN::invalidOperandException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class RPN::stackTooSmallException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class RPN::divisionByZeroException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class RPN::invalidExpressionException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif