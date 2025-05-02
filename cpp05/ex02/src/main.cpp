/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:38:55 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/22 12:50:00 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int	main(void) {
	/*
		comment out the below one
		check if the AForm is abstract
	*/
	// AForm tmp;
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "\ttest of the basics" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	try {
		Bureaucrat	bob("Bob", 5);
		ShrubberyCreationForm	first("old_world");
		bob.executeForm(first);
		bob.signForm(first);
		bob.executeForm(first);
		RobotomyRequestForm	second("myself");
		bob.signForm(second);
		bob.executeForm(second);
		PresidentialPardonForm third("Lovecraft");
		bob.signForm(third);
		bob.executeForm(third);
		std::cout << std::string(33, '#') << std::endl;
		std::cout << "\tdestructors called" << std::endl;
		std::cout << std::string(33, '#') << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Caught:" << e.what() << std::endl;
	}
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "\ttests with pointers" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	Bureaucrat	*jon;
	jon = Bureaucrat::tryNewBureaucrat("John", 75);
	RobotomyRequestForm	shr("Bob");
	jon->executeForm(shr);
	jon->signForm(shr);
	jon->executeForm(shr);
	delete jon;
	return (0);
}