/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:24:35 by craimond          #+#    #+#             */
/*   Updated: 2024/04/26 14:30:36 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdint.h>
# include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const uint8_t grade);
		void GradeTooHighException(void);
		void GradeTooLowException(void);
		std::string getName(void);
		uint8_t getGrade(void);
		~Bureaucrat();
	private:
		const std::string	_name;
		uint8_t				_grade;
};

#endif