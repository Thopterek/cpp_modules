#ifndef	SCHRUBBERYCREATIONFORM_HPP
#define	SCHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string set_target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
		/*
			OC form above
			below overwrite
			and proper getter
		*/
		void	action() const;
		std::string	const &getTarget() const;
		/*
			added new function to allocate form
			used later on by the intern
		*/
		static AForm	*newShrubbery(std::string set_target);
};

#endif