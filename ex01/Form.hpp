/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:41:24 by craimond          #+#    #+#             */
/*   Updated: 2024/04/26 18:28:49 by craimond         ###   ########.fr       */
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
		Form(const std::string &name, const int min_grade_to_sign);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();
		void FormAlreadySignedException(void) const;
		void GradeTooHighException(void) const;
		void GradeTooLowException(void) const;
		std::string getName(void) const;
		int getMinGrateToSign(void) const;
		bool isSigned(void) const;
		void beSigned(const Bureaucrat &b);
	private:
		const std::string	_name;
		bool 				_signed;
		const int			_min_grade_to_sign;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif