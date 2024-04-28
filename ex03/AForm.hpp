/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:40:28 by craimond          #+#    #+#             */
/*   Updated: 2024/04/26 19:56:23 by craimond         ###   ########.fr       */
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
	protected:
		void beExecuted(const Bureaucrat &executor) const;
		void GradeTooHighException(void) const;
		void GradeTooLowException(void) const;
		void FormAlreadySignedException(void) const;
		void FormNotSignedException(void) const;
	private:
		std::string		_name;
		bool 			_signed;
		int				_min_grade_to_sign;
		int				_min_grade_to_execute;
		std::string		_target;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif