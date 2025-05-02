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
};

#endif