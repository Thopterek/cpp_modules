#ifndef	AFORM_HPP
#define	AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <ctime>

/*
	added to fix circularity
	forward declaration
*/
class	Bureaucrat;

class	AForm {
	private:
		std::string const name;
		bool	is_signed;
		/*
			req stands for:
				required
		*/
		int const	req_to_sign;
		int const	req_to_exec;
	public:
		AForm();
		AForm(std::string name, int to_sign, int to_exec);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		/*
			per usual, above the OC Aform
			+ filling up the AForm values
			below the getters for private
		*/
		std::string const &getName() const;
		bool const	&getIsSigned() const;
		int const	&getReqToSign() const;
		int const	&getReqToExec() const;
		/*
			classes for the Aform exceptions
			mimicking those from the Bureaucrat
			with added exception if not signed
		*/
		class	GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class	FormNotSignedException : public std::exception {
			public:
				const char	*what() const throw();
		};
		/*
			extra function required from the subject
			changes the Aform status depending on Bureaucrat
			now we are also going to requirment for execution
		*/
		void	beSigned(const Bureaucrat &bure);
		void	execute(Bureaucrat const &executor) const;
		/*
			action is the one defined in the subclasses
			but execute is checking if it should be called
		*/
		virtual void	action() const = 0;
};
std::ostream	&operator<<(std::ostream &os, const AForm &form);

#endif