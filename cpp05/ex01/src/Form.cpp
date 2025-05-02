/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:38:26 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/18 14:21:07 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form()
:	name(""), is_signed(false), req_to_sign(75), req_to_exec(75)
{
	std::cout << "Form: default constructor" << std::endl;
}

Form::Form(std::string name, int to_sign, int to_exec)
:	name(name), is_signed(false), req_to_sign(to_sign), req_to_exec(to_exec)
{
	if (to_sign < 1 || to_exec < 1)
		throw GradeTooHighException();
	else if (to_sign > 150 || to_exec > 150)
		throw GradeTooLowException();
	std::cout << "Form: constructor taking the input" << std::endl;
}

Form::~Form() {
	std::cout << "Form: destructor called" << std::endl;
}

Form::Form(const Form &other)
:	name(other.name), is_signed(other.is_signed),
	req_to_sign(other.req_to_sign), req_to_exec(other.req_to_exec)
{
	std::cout << "Form: copy constructor" << std::endl;
}

Form	&Form::operator=(const Form &other) {
	static_cast<void>(other);
	std::cout << "Form: copy assingment doesn't make sense" << std::endl;
	return (*this);
}

std::string const	&Form::getName() const {
	return (name);
}

bool const	&Form::getIsSigned() const {
	return (is_signed);
}

int const	&Form::getReqToSign() const {
	return (req_to_sign);
}

int const	&Form::getReqToExec() const {
	return (req_to_exec);
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("FORM : GradeTooHigh : less than 1");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("FORM : GradeTooLow : more than 150");
}

void	Form::beSigned(const Bureaucrat &bure) {
	if (bure.getGrade() > getReqToSign())
		throw GradeTooLowException();
	is_signed = true;
}

std::ostream	&operator<<(std::ostream &os, const Form &form) {
	os << form.getName() << " has status: ";
	if (form.getIsSigned() == true) {
		os << "'signed', ";
	}
	else
		os << "'unsigned', ";
	os << "grade required to sign: " << form.getReqToSign();
	os << ", grade required to execute: " << form.getReqToExec();
	return (os);
}