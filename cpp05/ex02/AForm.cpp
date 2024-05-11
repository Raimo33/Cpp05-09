/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:41:17 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 14:25:04 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, const int min_grade_to_sign, const int min_grade_to_execute, const std::string &target) :
	_name(name),
	_signed(false),
	_min_grade_to_sign(min_grade_to_sign),
	_min_grade_to_execute(min_grade_to_execute),
	_target(target) {}

AForm::AForm(const AForm &copy) :
	_name(copy._name),
	_signed(copy._signed),
	_min_grade_to_sign(copy._min_grade_to_sign),
	_min_grade_to_execute(copy._min_grade_to_execute),
	_target(copy._target) {}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		_name = copy.getName();
		_signed = copy.isSigned();
		_min_grade_to_sign = copy.getMinGrateToSign();
		_min_grade_to_execute = copy.getMinGrateToExecute();
		_target = copy.getTarget();
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName(void) const
{
	return _name;
}

std::string AForm::getTarget(void) const
{
	return _target;
}

int AForm::getMinGrateToSign(void) const
{
	return _min_grade_to_sign;
}

int AForm::getMinGrateToExecute(void) const
{
	return _min_grade_to_execute;
}

bool AForm::isSigned(void) const
{
	return _signed;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (isSigned())
		throw AlreadySignedException();
	if (b.getGrade() > _min_grade_to_sign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::beExecuted(const Bureaucrat &executor) const
{
	try
	{
		if (!isSigned())
			throw NotSignedException();
		if (executor.getGrade() > getMinGrateToExecute())
			throw GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << executor.getName() << " cannot execute " << getName() << ". Reason: " << e.what() << std::endl;
		return;
	}
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << f.getName() << ", with minimum required grade " << f.getMinGrateToSign() << ", is ";
	if (f.isSigned())
		os << "signed";
	else
		os << "not signed";
	os << std::endl;
	return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}
