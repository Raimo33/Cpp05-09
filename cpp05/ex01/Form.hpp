/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:41:24 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 14:21:54 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string &name, const int min_grade_to_sign, const int min_grade_to_execute);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();
		std::string getName(void) const;
		int getMinGrateToSign(void) const;
		bool isSigned(void) const;
		void beSigned(const Bureaucrat &b);
		class GradeTooHighException;
		class GradeTooLowException;
		class AlreadySignedException;
	private:
		const std::string	_name;
		bool 				_signed;
		const int			_min_grade_to_sign;
		const int			_min_grade_to_execute;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

class Form::GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class Form::AlreadySignedException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif