/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:15:45 by craimond          #+#    #+#             */
/*   Updated: 2024/05/02 17:23:29 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void	check_args(int argc, char **argv);

int main(int argc, char **argv)
{
	check_args(argc, argv);
	BitcoinExchange exchange(DATA_FILE);
	exchange.convertToValues(argv[1]);
}

static void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		exit(1);
	}
	if (std::string(argv[1]).find(".csv") == std::string::npos)
	{
		std::cerr << "Error: input file must be a .csv file" << std::endl;
		exit(1);
	}
}