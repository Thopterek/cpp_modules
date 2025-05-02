/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:20:15 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/29 11:39:40 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	static_cast<void>(other);
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other) {
	static_cast<void>(other);
	return (*this);
}

void	ScalarConverter::convert(std::string input) {
	InputType unknown = checkType(input);
	if (InputType::Unknown == unknown) {
		print_error();
		return ;
	}
	unknown = doubleCheck(input, unknown);
	if (InputType::Unknown == unknown) {
		print_error();
		return ;
	}
	switch (unknown) {
		case (InputType::Character):
			convertChar(input); break;
		case (InputType::Integer):
			convertInt(input); break;
		case (InputType::Float):
			convertFloat(input, get_precision(input)); break;
		case (InputType::ScienceFloat):
			convertScienceFloat(input); break;
		case (InputType::Double):
			convertDouble(input, get_precision(input)); break;
		case (InputType::ScienceDouble):
			convertScienceDouble(input); break;
		default:
			std::cerr << "Error: type outside of all the scopes (char/int/float/double)" << std::endl;
	}
}