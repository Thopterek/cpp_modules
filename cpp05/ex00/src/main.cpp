/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:38:55 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/18 12:04:57 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

/*
	Without the wrapper like the tryNewBureaucrat to create it
	we could test it simpler but with way more redundant code:
	try {
		bob = new Bureaucrat("Bob", 1);
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Caught exception for init: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Caught exception for init: " << e.what() << std::endl;
	}
*/
int	main(void) {
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "\ttest using wrappers" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	Bureaucrat	*bob = Bureaucrat::tryNewBureaucrat("Bob", 0);
	bob = Bureaucrat::tryNewBureaucrat("Bob", 151);
	bob = Bureaucrat::tryNewBureaucrat("Bob", 1);
	if (bob != 0) {
		std::cout << "Here is our guy: " << *bob << std::endl;
		bob->tryHigherGrade();
		std::cout << *bob << std::endl;
		bob->tryLowerGrade();
		std::cout << *bob << std::endl;
		delete bob;
	}
	else
		std::cout << "There is NOT A SINGLE SOUL who survived" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "\tless confusing test" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	try {
		Bureaucrat	john("Johnny", 75);
		std::cout << john << std::endl;
		john.tryHigherGrade();
		std::cout << john << std::endl;
		john.tryLowerGrade();
		std::cout << john << std::endl;
		Bureaucrat	max("Max", 150);
		std::cout << max << std::endl;
		max.setOneLower();
	} catch (const std::exception &e) {
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}
	return (0);
}