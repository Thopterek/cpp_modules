/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:53:45 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/02 11:02:56 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

static void	print_header(std::string input) {
	std::cout << std::string(input.size(), '#') << std::endl;
	std::cout << input << std::endl;
	std::cout << std::string(input.size(), '#') << std::endl;
}

/*
	saving the tip:
	Try to compile int * a = new int();
	then display *a
	https://cppinsights.io/
	understanding cpp compiler
*/
int	main(void) {
	print_header("Persubject showing how it should work");
	int	*a = new int();
	std::cout << a << std::endl;
	std::cout << *a << std::endl;
	delete a;
	print_header("Actual tests of class Array, ints");
	Array<int> b(2);
	b[0] = 42; b[1] = 123;
	std::cout << &b << std::endl;
	std::cout << b[0] << " <-first and second int-> " << b[1] << std::endl;
	print_header("trying to throw error on that array");
	try {
		std::cout << b[2] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	print_header("now for the string type and copy");
	Array<std::string> strings(3);
	strings[0] = "Hello"; strings[1] = " World"; strings[2] = "!";
	std::cout << strings[0] << strings[1] << strings[2] << std::endl;
	Array<std::string> another(strings);
	std::cout << another[0] << another[1] << another[2] << std::endl;
	print_header("modify and use of = operator");
	another[0] = "Changed"; another[1] = " this "; another[2] = "array";
	std::cout << another[0] << another[1] << another[2] << std::endl;
	strings = another;
	std::cout << strings[0] << strings[1] << strings[2] << std::endl;
	print_header("printing the number of elements for each array");
	std::cout << "Array of ints: " << b.size() << std::endl;
	std::cout << "Array of strings: " << strings.size() << std::endl;
	std::cout << "Another array of strings: " << another.size() << std::endl;
	return (EXIT_SUCCESS);
}