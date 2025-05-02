#ifndef	FORM_HPP
#define	FORM_HPP

#include <iostream>
#include <exception>

/*
	added to fix circularity
	forward declaration
*/
class	Bureaucrat;

class	Form {
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
		Form();
		Form(std::string name, int to_sign, int to_exec);
		~Form();
		Form(const Form &other);
		Form	&operator=(const Form &other);
		/*
			per usual, above the OC form
			+ filling up the Form values
			below the getters for private
		*/
		std::string const &getName() const;
		bool const	&getIsSigned() const;
		int const	&getReqToSign() const;
		int const	&getReqToExec() const;
		/*
			classes for the form exceptions
			mimicking those from the Bureaucrat
		*/
		class	GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};
		/*
			extra function required from the subject
			changes the form status depending on Bureaucrat
		*/
		void	beSigned(const Bureaucrat &bure);
};
std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif