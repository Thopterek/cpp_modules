/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:42:02 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/30 17:43:14 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	replace(int &av) {
	av = 5;
}

void	str_change(std::string &tmp) {
	tmp = "changed";
}

int	main(void) {
	int array[5] = {0, 0, 0, 0, 0};
	std::string str_array[3] = {"str", "str", "str"};
	for (int i = 0; i < 5; i++)
		std::cout << "numbers in arr: " << array[i] << std::endl;
	::iter(array, 5, replace);
	std::cout << "now I used iter on that array" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "numbers in arr: " << array[i] << std::endl;
	std::cout << "the same thing for the string array" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << "strings in array: " << str_array[i] << std::endl;
	::iter(str_array, 3, str_change);
	for (int i = 0; i < 3; i++)
		std::cout << "strings in array: " << str_array[i] << std::endl;
	return (EXIT_SUCCESS);
}