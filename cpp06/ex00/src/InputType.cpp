/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:16:06 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/29 15:18:14 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/InputType.hpp"

void	convertDouble(std::string &input, int precision) {
	double	check = stod(input);
	if (check < 33 || check > 126)
		std::cout << "char: Non displayable" << std::endl;
	else {
		char c = static_cast<char>(check);
		std::cout << "char: " << c << std::endl;
	}
	if (check < std::numeric_limits<int>::min() || check > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else {
		int	i = static_cast<int>(check);
		std::cout << "int: " << i << std::endl;
	}
	float f = static_cast<float>(check);
	std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << check << std::endl;
}

void	convertFloat(std::string &input, int precision) {
	float	check = stof(input);
	if (check < 33 || check > 126)
		std::cout << "char: Non displayable" << std::endl;
	else {
		char c = static_cast<char>(check);
		std::cout << "char: " << c << std::endl;
	}
	if (check < std::numeric_limits<int>::min() || check > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else {
		int	i = static_cast<int>(check);
		std::cout << "int: " << i << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(precision) << check << "f" << std::endl;
	double d = static_cast<double>(check);
	std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;	
}

void	convertInt(std::string &input) {
	int check = stoi(input);
	if (check < 33 || check > 126)
		std::cout << "char: Non displayable" << std::endl;
	else {
		char c = static_cast<char>(check);
		std::cout << "char: " << c << std::endl;
	}
	std::cout << "int: " << check << std::endl;
	float f = static_cast<float>(check);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	double d = static_cast<double>(check);
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	convertChar(std::string &input) {
	char check = static_cast<char>(input[0]);
	if (check < 33 || check > 126)
		std::cout << "char: Non displayable" << std::endl;
	else {
		char c = static_cast<char>(check);
		std::cout << "char: " << c << std::endl;
	}
	int	i = static_cast<int>(check);
	std::cout << "int: " << i << std::endl;
	float f = static_cast<float>(check);
	std::cout << "float: " << f << "f" << std::endl;
	double d = static_cast<double>(check);
	std::cout << "double: " << d << std::endl;
}

int	get_precision(std::string &input) {
	if (input.find(".") == std::string::npos)
		return (0);
	else if (input.find("f") == std::string::npos)
		return (input.size() - input.find(".") - 1);
	else
		return (input.size() - input.find(".") - 2);
}

/*
	if the above conversions are not applicable
	we are using this print error function
*/
void	print_error() {
	std::cerr << "Error: type outside of the scope (char/int/float/double)" << std::endl;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

/*
	weirdest cases include
	float: +.0f or -.0f
	double: NaN or nan
*/
InputType	checkType(std::string &input) {
	std::regex	float_pattern(R"(^([+-]?\d*\.\d+((f{1})$)|[+-]?in(f{2})$)|nanf)");
	std::regex	double_pattern(R"([+-]?\d+\.\d+|[+-]?inf|nan|NaN)");
	std::regex	int_pattern(R"([+-]?\d+)");
	if (input.size() == 1 && std::isdigit(static_cast<char>(input[0])) == 0)
		return (InputType::Character);
	else if (std::regex_match(input, float_pattern))
		return (InputType::Float);
	else if (std::regex_match(input, double_pattern))
		return (InputType::Double);
	else if (std::regex_match(input, int_pattern))
		return (InputType::Integer);
	return (InputType::Unknown);
}

/*
	double checking for the proper max and min
	and the special values that might come
*/
InputType	doubleCheck(std::string &input, InputType &type) {
	if (type == InputType::Character)
		return (InputType::Character);
	std::regex	uncommon_float(R"([+-]?inff|nanf)");
	std::regex	uncommon_double(R"([+-]?inf|nan|NaN)");
	if (std::regex_match(input, uncommon_float))
		return (InputType::ScienceFloat);
	else if (std::regex_match(input, uncommon_double))
		return (InputType::ScienceDouble);
	switch (type) {
		case (InputType::Integer):
			try {
				int check = std::stoi(input);
				if (check >= std::numeric_limits<int>::min() && check <= std::numeric_limits<int>::max())
					return (InputType::Integer);
				break ;
			} catch (std::exception &e) {
				std::cerr << "Written like integer but not in the limits" << std::endl;
				return (InputType::Unknown);
			}
		case (InputType::Float):
			try {
				float check = std::stof(input);
				if (check > std::numeric_limits<float>::lowest() && check < std::numeric_limits<float>::max())
					return (InputType::Float);
				break ;
			} catch (std::exception &e) {
				std::cerr << "Written like float but not in the limits" << std::endl;
				return (InputType::Unknown);
			} 
		case (InputType::Double):
			try {
				double check = std::stod(input);
				if (check > std::numeric_limits<double>::lowest() && check < std::numeric_limits<double>::max())
					return (InputType::Double);
				break ;
			} catch (std::exception &e) {
				std::cerr << "Written like double but not in the limits" << std::endl;
				return (InputType::Unknown);
			}
		default:
			return (InputType::Unknown);
	}
	return (InputType::Unknown);
}

void	convertScienceFloat(std::string &input) {
	float	check = stod(input);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << check << "f" << std::endl;
	double d = static_cast<double>(check);
	std::cout << "double: " << d << std::endl;	
}

void	convertScienceDouble(std::string &input) {
	double	check = stod(input);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	float f = static_cast<float>(check);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << check << std::endl;	
}