/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:37:21 by craimond          #+#    #+#             */
/*   Updated: 2024/04/28 17:02:05 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

Intern::Intern(const Intern &copy)
{
	operator=(copy);
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	static const std::string form_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	static AForm *(*form_creators[])(const std::string &target) = {createShrubberyCreationForm, createRobotomyRequestForm, createPresidentialPardonForm};
	static const int n_forms = sizeof(form_names) / sizeof(form_names[0]);

	if (target.empty())
		std::cerr << "Intern cannot create form without target" << std::endl;
	for (int i = 0; i < n_forms; i++)
	{
		if (name == form_names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (form_creators[i](target));
		}	
	}
	std::cerr << "Intern cannot create form with name: '" << name <<"'" << std::endl;
	return (NULL);
}
