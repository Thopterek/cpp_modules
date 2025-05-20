/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:28:02 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/20 17:49:59 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

static void	print_exit(std::string msg) {
	std::cerr << "Error: " << msg << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av) {
	if (ac != 2)
		print_exit("usage ./RPN <set of numbers and tokens in quotes>");
	std::string	input = av[1];
	std::regex	rpn_pattern(R"([0-9]+[0-9*-/+ ]+)");
	std::regex	two_digits(R"(\d{2,})");
	if (regex_match(input, rpn_pattern) == false)
		print_exit("only numbers, spaces and * / - + allowed");
	if (std::regex_search(input, two_digits))
		print_exit("only one digit numbers are allowed");
	if (input.empty())
		print_exit("there is no input calculate on");
	RPN	ls;
	ls.calculator(input);
	return (EXIT_SUCCESS);
}