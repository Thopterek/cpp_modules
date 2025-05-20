/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:34:31 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/19 12:45:48 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

static void	print_exit(std::string msg) {
	std::cerr << "Error: " << msg << std::endl;
	exit(EXIT_FAILURE);
}

static void	check_input(BitcoinExchange &data, int ac, char **av) {
	if (ac != 2)
		print_exit("usage ./btc <file_to_evaluate>");
	std::string	file_name = std::string("data/") + av[1];
	std::ifstream	file_user(file_name);
	if (file_user.good() == false)
		print_exit("file not found, check spelling");
	std::ifstream	file_data("data/data.csv");
	if (file_data.good() == false)
		print_exit("database not found, save it in directory data as 'data.csv'");
	std::string	header;
	getline(file_user, header);
	if ("date | value" != header)
		print_exit("wrong header in your data, should be 'date | value'");
	getline(file_data, header);
	if ("date,exchange_rate" != header)
		print_exit("wrong header in database, should be 'date,exchange_rate'");
	if (data.LoadDatabase(file_data) == false)
		print_exit("loading the data from data.csv failed");
	data.CheckUserData(file_user);
}

int	main(int ac, char **av) {
	BitcoinExchange	data;
	check_input(data, ac, av);
	return (EXIT_SUCCESS);
}