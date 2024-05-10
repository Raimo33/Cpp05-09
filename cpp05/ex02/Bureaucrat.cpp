/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:06 by craimond          #+#    #+#             */
/*   Updated: 2024/05/10 16:24:02 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name)
{
	if (grade < 1)
		GradeTooHighException();
	else if (grade > 150)
		GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	_grade = copy._grade;
	return *this;
}

void Bureaucrat::GradeTooHighException(void) const
{
	throw std::runtime_error("Grade is too high");
}

void Bureaucrat::GradeTooLowException(void) const
{
	throw std::runtime_error("Grade is too low");
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::SignForm(AForm &f) const
{
	if (f.isSigned())
		throw std::runtime_error("Form is already signed");
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::ExecuteForm(const AForm &f) const
{
	f.execute(*this);
	std::cout << getName() << " executed " << f.getName() << std::endl;
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		GradeTooLowException();
	_grade++;
}

std::string Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
