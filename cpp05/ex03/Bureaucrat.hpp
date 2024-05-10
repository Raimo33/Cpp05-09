/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:24:35 by craimond          #+#    #+#             */
/*   Updated: 2024/05/10 16:24:44 by craimond         ###   ########.fr       */
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
		std::string getName(void) const;
		int getGrade(void) const;
	protected:
		void GradeTooHighException(void) const;
		void GradeTooLowException(void) const;
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif