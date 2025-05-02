/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:38:55 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/22 15:00:03 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"

int	main(void) {
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "\tworking interns" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	Intern	depressed_student;
	AForm *new_form = depressed_student.makeForm("Form that doesn't exist", "Bobby");
	new_form = depressed_student.makeForm("PresidentialPardonForm", "Bobby");
	Bureaucrat *bob = Bureaucrat::tryNewBureaucrat("Bobby", 151);
	bob = Bureaucrat::tryNewBureaucrat("Bobby", -10);
	bob = Bureaucrat::tryNewBureaucrat("Bobby", 26);
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "\texec & sign" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	bob->executeForm(*new_form);
	bob->signForm(*new_form);
	bob->tryHigherGrade();
	bob->signForm(*new_form);
	bob->executeForm(*new_form);
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "\tdestructors" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	if (new_form != 0)
		delete new_form;
	if (bob != 0)
		delete bob;
	return (0);
}