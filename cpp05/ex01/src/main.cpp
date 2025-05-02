/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:38:55 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/18 14:23:02 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

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
	if (bob != 0)
		std::cout << "Here is our guy: " << *bob << std::endl;
	else
		std::cout << "There is NOT A SINGLE SOUL who survived" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "\tchecking basic form" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	try {
		Form proper("Proper_name", 10, 3);
		std::cout << proper << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Form caught: " << e.what() << std::endl;
	}
	Form	*point_form;
	try {
		point_form = new Form("Too_high_sign_form", 0, 30);
	}	catch (const std::exception &e) {
		std::cerr << "Form caught: " << e.what() << std::endl;
	}
	try {
		point_form = new Form("Too_low_sign_form", 151, 30);
	}	catch (const std::exception &e) {
		std::cerr << "Form caught: " << e.what() << std::endl;
	}
	try {
		point_form = new Form("okay_form", 30, 30);
		std::cout << *point_form << std::endl;
	}	catch (const std::exception &e) {
		std::cerr << "Form caught: " << e.what() << std::endl;
	}
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "\tchecking the signing" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	try {
		Bureaucrat	mid("Mid_name", 75);
		std::cout << mid << std::endl;
		Form	low_form("Low_Form", 150, 150);
		std::cout << low_form << std::endl;
		mid.signForm(low_form);
		std::cout << low_form << std::endl;
		Form	high_form("High_form", 1, 1);
		std::cout << high_form << std::endl;
		mid.signForm(high_form);
		std::cout << high_form << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception called: " << e.what() << std::endl;
	}
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "\tcalling destructors" << std::endl;
	std::cout << "\ton manual memory" << std::endl;
	std::cout << std::string(33, '#') << std::endl;	
	if (bob != 0)
		delete bob;
	if (point_form != 0)
		delete point_form;
	return (0);
}