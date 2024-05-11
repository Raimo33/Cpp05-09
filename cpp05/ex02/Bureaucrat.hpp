/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:24:35 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 14:03:17 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdint.h>
# include <stdexcept>
# include <string>
# include <iostream>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, const int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();
		void SignForm(AForm &f) const;
		void ExecuteForm(AForm const &form) const;
		void incrementGrade(void);
		void decrementGrade(void);
		class GradeTooHighException;
		class GradeTooLowException;
		std::string getName(void) const;
		int getGrade(void) const;
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif