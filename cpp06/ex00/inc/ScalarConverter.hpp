#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <iostream>
#include "InputType.hpp"

class	ScalarConverter {
	/*
		in C++11 you can write
		ScalarConverter() = delete
		as for C++98 it seems best
		to put constructs in private
	*/
	private:
		ScalarConverter() = delete;
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
	public:
		/*
			only one static method below
			above the OC form as always
		*/
		static void	convert(std::string input);
};

#endif