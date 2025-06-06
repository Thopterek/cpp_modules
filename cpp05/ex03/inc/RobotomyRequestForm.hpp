#ifndef	ROBOTOMYREQUESTFORM_HPP
#define	ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string set_target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
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
		static AForm	*newRobotomy(std::string set_target);
};

#endif