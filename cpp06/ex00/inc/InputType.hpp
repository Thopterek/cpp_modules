#ifndef	INPUTTYPE_HPP
#define	INPUTTYPE_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <regex>
#include <limits>

enum class	InputType {
	Character,
	Integer,
	Float,
	ScienceFloat,
	Double,
	ScienceDouble,
	Unknown
};

InputType	checkType(std::string &input);
/*
	above the first check for main 4
	categories if its the right input
	below the basic conversions plus
	error if anything is outside of it
*/
void	convertChar(std::string &input);
void	convertInt(std::string &input);
void	convertFloat(std::string &input, int precision);
void	convertDouble(std::string &input, int precision);
void	print_error();
/*
	below the extra check to differentiate
	between scientific notation and standard
	plus 2 extra conversion types related
*/
InputType	doubleCheck(std::string &input, InputType &type);
void	convertScienceFloat(std::string &input);
void	convertScienceDouble(std::string &input);
/*
	helper function for float and doubles
	to get the proper precision for Float/Double
*/
int	get_precision(std::string &input);

#endif