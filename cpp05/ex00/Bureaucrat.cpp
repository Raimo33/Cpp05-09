/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:06 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 14:00:50 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	_grade = copy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
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

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
