/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:40:28 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 14:34:14 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, const int min_grade_to_sign, const int min_grade_to_execute, const std::string &target);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();
		std::string getName(void) const;
		std::string getTarget(void) const;	
		int getMinGrateToSign(void) const;
		int getMinGrateToExecute(void) const;
		bool isSigned(void) const;
		void beSigned(const Bureaucrat &b);
		virtual void execute(const Bureaucrat &executor) const = 0;
		class GradeTooHighException;
		class GradeTooLowException;
		class AlreadySignedException;
		class NotSignedException;
	protected:
		void beExecuted(const Bureaucrat &executor) const;
	private:
		std::string		_name;
		bool 			_signed;
		int				_min_grade_to_sign;
		int				_min_grade_to_execute;
		std::string		_target;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

class AForm::GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class AForm::AlreadySignedException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class AForm::NotSignedException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif