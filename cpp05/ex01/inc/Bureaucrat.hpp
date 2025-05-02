#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>
#include <exception>

/*
	added to fix circularity
	forward declaration
*/
class	Form;

class	Bureaucrat {
	private:
		std::string const name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);
		/*
			above the OC form with added constructor with input
			below the required getters, setter changes
		*/
		std::string const &getName() const;
		int	const &getGrade() const;
		void	setOneHigher();
		void	setOneLower();
		/*
			exception class related to the base
			catching the errors from it
		*/
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		/*
			for better usage and cleaner use
			try blocks for testing in case:
				- the new allocation
				- setting grade higher
				- setting grade lower
		*/
		static Bureaucrat	*tryNewBureaucrat(std::string name, int grade);
		void	tryHigherGrade();
		void	tryLowerGrade();
		/*
			new member function
			calling Form::beSigned()
		*/
		void	signForm(Form &form);
};
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bure);


#endif