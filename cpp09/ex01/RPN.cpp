/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:53:03 by craimond          #+#    #+#             */
/*   Updated: 2024/05/09 15:50:05 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _stack() {}

RPN::~RPN() {}

void RPN::addOperand(const char op)
{
	int n1, n2;

	if (_stack.size() < 2)
		throw StackTooSmallException();
	n2 = _stack.top();
	_stack.pop();
	n1 = _stack.top();
	_stack.pop();
	switch (op)
	{
		case '+':
			_stack.push(n1 + n2);
			break;
		case '-':
			_stack.push(n1 - n2);
			break;
		case '/':
			if (n2 == 0)
				throw DivisionByZeroException();
			_stack.push(n1 / n2);
			break;
		case '*':
			_stack.push(n1 * n2);
			break;
		default:
			throw InvalidOperandException();
			break;
	}
}

void RPN::addNumber(const int n)
{
	_stack.push(n);
}

int	RPN::getResult(void) const
{
	if (_stack.size() > 1)
		throw InvalidRNPExpressionException();
	return (_stack.top());
}
