/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:52:13 by craimond          #+#    #+#             */
/*   Updated: 2024/05/09 17:28:39 by craimond         ###   ########.fr       */
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
	private:
		std::stack<int>	_stack;
};

class RPNException : public std::exception
{
	public:
		RPNException(const std::string &msg) : _message(msg) {}
		~RPNException() throw() {}
		virtual const char *what() const throw()
		{
			return _message.c_str();
		}
	protected:
		std::string	_message;
};

class InvalidOperandException : public RPNException
{
	public:
		InvalidOperandException() : RPNException("Error: invalid operand") {}
};

class StackTooSmallException : public RPNException
{
	public:
		StackTooSmallException() : RPNException("Error: stack too small") {}
};

class DivisionByZeroException : public RPNException
{
	public:
		DivisionByZeroException() : RPNException("Error: division by zero") {}
};

class InvalidRNPExpressionException : public RPNException
{
	public:
		InvalidRNPExpressionException() : RPNException("Error: invalid RPN expression") {}
};

#endif