/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:38:26 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/22 10:07:40 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm()
:	name(""), is_signed(false), req_to_sign(75), req_to_exec(75)
{
	std::cout << "Form: default constructor" << std::endl;
}

AForm::AForm(std::string name, int to_sign, int to_exec)
:	name(name), is_signed(false), req_to_sign(to_sign), req_to_exec(to_exec)
{
	if (to_sign < 1 || to_exec < 1)
		throw GradeTooHighException();
	else if (to_sign > 150 || to_exec > 150)
		throw GradeTooLowException();
	std::cout << "Form: constructor taking the input" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm: destructor called" << std::endl;
}

AForm::AForm(const AForm &other)
:	name(other.name), is_signed(other.is_signed),
	req_to_sign(other.req_to_sign), req_to_exec(other.req_to_exec)
{
	std::cout << "AForm: copy constructor" << std::endl;
}

AForm	&AForm::operator=(const AForm &other) {
	static_cast<void>(other);
	std::cout << "AForm: copy assingment doesn't make sense" << std::endl;
	return (*this);
}

std::string const	&AForm::getName() const {
	return (name);
}

bool const	&AForm::getIsSigned() const {
	return (is_signed);
}

int const	&AForm::getReqToSign() const {
	return (req_to_sign);
}

int const	&AForm::getReqToExec() const {
	return (req_to_exec);
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("AFORM : GradeTooHigh : less than 1");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("AFORM : GradeTooLow : more than 150");
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return ("AFORM : FormNotSigned, sign before executing");
}

void	AForm::beSigned(const Bureaucrat &bure) {
	if (bure.getGrade() > getReqToSign())
		throw GradeTooLowException();
	is_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (getIsSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > getReqToExec())
		throw GradeTooLowException();
	action();
}

std::ostream	&operator<<(std::ostream &os, const AForm &form) {
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