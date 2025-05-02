/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:14:36 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/22 14:43:36 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {
	std::cout << "INTERN: Default" << std::endl;
}

Intern::~Intern() {
	std::cout << "INTERN: Destructor" << std::endl;
}

Intern::Intern(const Intern &other) {
	static_cast<void>(other);
	std::cout << "INTERN: copy constructor, nothing to copy" << std::endl;
}


Intern	&Intern::operator=(const Intern &other) {
	static_cast<void>(other);
	std::cout << "INTERN: copy assingment, but does nothing" << std::endl;
	return (*this);
}

/*
	telling the compiler inside the new_forms
	that every function has AForm *function(std::string)
	having a reference to static functions
*/
AForm	*Intern::makeForm(std::string name, std::string target) {
	std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm	*(*new_forms[3])(std::string) = {
		&PresidentialPardonForm::newPresidential,
		&RobotomyRequestForm::newRobotomy,
		&ShrubberyCreationForm::newShrubbery
	};
	for (int i = 0; i < 3; i++) {
		if (name.compare(forms[i]) == 0) {
			std::cout << "Intern creates " << forms[i] << std::endl;
			return ((new_forms[i])(target));
		}
	}
	std::cout << "Intern failed to create a form: '" << name << "' is not known form" << std::endl;
	return (0);
}