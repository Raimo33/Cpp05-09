/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:41:17 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 14:22:01 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
	_name("default"),
	_signed(false),
	_min_grade_to_sign(150),
	_min_grade_to_execute(150){}

Form::Form(const std::string &name, const int min_grade_to_sign, const int min_grade_to_execute) :
	_name(name),
	_signed(false),
	_min_grade_to_sign(min_grade_to_sign),
	_min_grade_to_execute(min_grade_to_execute) {}

Form::Form(const Form &copy) :
	_name(copy._name),
	_signed(copy._signed),
	_min_grade_to_sign(copy._min_grade_to_sign),
	_min_grade_to_execute(copy._min_grade_to_execute) {}

Form &Form::operator=(const Form &copy)
{
	_signed = copy._signed;
	return *this;
}

Form::~Form() {}

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
	if (isSigned())
		throw AlreadySignedException();
	if (b.getGrade() > _min_grade_to_sign)
		throw GradeTooLowException();
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

const char *Form::GradeTooHighException::what() const throw()
{
	return "Error: Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Error: Grade is too low";
}

const char *Form::AlreadySignedException::what() const throw()
{
	return "Error: Form is already signed";
}

