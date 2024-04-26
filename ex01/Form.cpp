/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:41:17 by craimond          #+#    #+#             */
/*   Updated: 2024/04/26 16:17:10 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, const int min_grade_to_sign) : _name(name), _signed(false), _min_grade_to_sign(min_grade_to_sign) {}

Form::~Form() {}

void Form::GradeTooHighException(void) const
{
	throw std::runtime_error("Grade is too high");
}

void Form::GradeTooLowException(void) const
{
	throw std::runtime_error("Grade is too low");
}

std::string Form::getName(void) const
{
	return _name;
}

int Form::getMinGrateToSign(void) const
{
	return _min_grade_to_sign;
}

bool Form::isSigned(void) const
{
	return _signed;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _min_grade_to_sign)
		GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << f.getName() << ", with minimum required grade " << f.getMinGrateToSign() << ", is ";
	if (f.isSigned())
		os << "signed";
	else
		os << "not signed";
	os << std::endl;
	return os;
}

