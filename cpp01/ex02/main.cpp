/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:32:33 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 10:39:09 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

/*
	memory adds option to use:
		std::addressof()
*/
int	main() {
	/*
		initial state
		per the subject
	*/
	std::string variable = "HI THIS IS BRAIN";
	std::string *stringPTR = &variable;
	std::string &stringREF = variable;
	/*
		getting the address of each of them
			plus outputing for the check
	*/
	std::cout << std::addressof(variable) << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << std::addressof(stringREF) << std::endl;
	/*
		now outputting the values they hold
		or they are pointing two (ref, ptr)
	*/
	std::cout << variable << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}