#ifndef	INTERN_HPP
#define	INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		/*
			above the OC form per usual
			below creating the new forms
		*/
		AForm	*makeForm(std::string name, std::string target);
};
#endif