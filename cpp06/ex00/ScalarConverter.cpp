/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:26:32 by craimond          #+#    #+#             */
/*   Updated: 2024/04/28 19:31:26 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void convert_char(const std::string &str);
void convert_int(const std::string &str);
void convert_float(const std::string &str);
void convert_double(const std::string &str);
bool isCharLiteral(const std::string &str);
bool isDisplayable(const int c);

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool isCharLiteral(const std::string &str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool isDisplayable(const int c)
{
	return (c >= 32 && c <= 126);
}

bool isPseudoLiteral(const std::string &str)
{
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff");
}

void ScalarConverter::convert(const std::string &str)
{
	convert_char(str);
	convert_int(str);
	convert_float(str);
	convert_double(str);
}

void convert_char(const std::string &str)
{
	std::cout << "char: ";
	if (isCharLiteral(str))
		std::cout << "'" << str[1] << "'" << std::endl;
	else if (isPseudoLiteral(str))
		std::cout << "Impossible" << std::endl;
	else
	{
		std::istringstream	stream(str);
		int					i;

		if (stream >> i)
		{
			if (isDisplayable(i))
				std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
		}
		else
			std::cout << "Impossible" << std::endl;
	}
}

void convert_int(const std::string &str)
{
	std::cout << "int: ";
	if (isCharLiteral(str))
		std::cout << static_cast<int>(str[1]) << std::endl;
	else if (isPseudoLiteral(str))
		std::cout << "Impossible" << std::endl;
	else
	{
		std::istringstream	stream(str);
		int					i;

		if (stream >> i)
			std::cout << i << std::endl;
		else
			std::cout << "Impossible" << std::endl;	
	}
}

void convert_float(const std::string &str)
{
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1);
	if (isCharLiteral(str))
		std::cout << static_cast<float>(str[1]) << "f" << std::endl;
	else if (isPseudoLiteral(str))
	{
		if (str == "nan" || str == "nanf")
			std::cout << "nanf" << std::endl;
		else if (str == "+inf" || str == "+inff")
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
	{
		std::istringstream	stream(str);
		float				f;

		if (stream >> f)
			std::cout << f << "f" << std::endl;
		else
			std::cout << "Impossible" << std::endl;
	}
	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
}

void convert_double(const std::string &str)
{
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1);
	if (isCharLiteral(str))
		std::cout << static_cast<double>(str[1]) << std::endl;
	else if (isPseudoLiteral(str))
	{
		if (str == "nan" || str == "nanf")
			std::cout << "nan" << std::endl;
		else if (str == "+inf" || str == "+inff")
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
	{
		std::istringstream	stream(str);
		double				d;

		if (stream >> d)
			std::cout << d << std::endl;
		else
			std::cout << "Impossible" << std::endl;
	}
	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
}
