/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:54:09 by craimond          #+#    #+#             */
/*   Updated: 2024/04/26 19:58:21 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main(void)
{
	Bureaucrat b("Craimond", 76);
	std::cout << b << std::endl;

	RobotomyRequestForm rrf("Bender");
	PresidentialPardonForm ppf("Zaphod");
	ShrubberyCreationForm scf("Marvin");

	b.SignForm(rrf);
	b.SignForm(ppf);
	b.SignForm(scf);

	b.ExecuteForm(rrf);
	b.ExecuteForm(ppf);
	b.ExecuteForm(scf);
	return 0;
}