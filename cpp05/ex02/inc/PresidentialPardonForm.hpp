#ifndef	PRESIDENTIALPARDONFORM_HPP
#define	PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	private:
		std::string	target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string set_target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		/*
			OC form above
			below overwrite
			and proper getter
		*/
		void	action() const;
		std::string	const &getTarget() const;
};

#endif