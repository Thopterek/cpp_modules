/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:38:58 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/18 14:10:12 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Bureaucrat::Bureaucrat()
:	name("Default_name"), grade(75)
{
	std::cout << "BURE: Default constructor with grade in the middle" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
:	name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "BURE: " << getName() << " succesfully constructed" << std::endl;
	this->grade = grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "BURE: " << getName() << " destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
:	name(other.name), grade(other.grade)
{
	std::cout << "BURE: Copy constructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "BURE: Copy assingment, but name is unchanged" << std::endl;
	if (this != &other) {
		grade = other.grade;
	}
	return (*this);
}

std::string const &Bureaucrat::getName() const {
	return (name);
}

int	const &Bureaucrat::getGrade() const {
	return (grade);
}

void	Bureaucrat::setOneHigher() {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	std::cout << getName() << ", grade change went okay (higher)" << std::endl;
	this->grade -= 1;
}

void	Bureaucrat::setOneLower() {
	if (grade + 1 > 150)
		throw GradeTooLowException();
	std::cout << getName() << ", grade change went okay (lower is +)" << std::endl;
	this->grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("BURE : GradeTooHigh : less than 1, exception called");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("BURE : GradeTooLow : more than 150 exception called");
}

Bureaucrat	*Bureaucrat::tryNewBureaucrat(std::string name, int grade) {
	Bureaucrat	*bure = 0;
	try {
		bure = new Bureaucrat(name, grade);
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Caught exception for init: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Caught exception for init: " << e.what() << std::endl;
	}
	return (bure);
}

void	Bureaucrat::tryHigherGrade() {
	try {
		this->setOneHigher();
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Caught exception when changing grade (-)" << std::endl;
	}
}

void	Bureaucrat::tryLowerGrade() {
	try {
		this->setOneLower();
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Caught exception when changing grade (+)" << std::endl;
	}
}

void	Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cerr << getName() << " couldn't sign " << std::flush;
		std::cerr << form.getName() << " because " << std::flush;
		std::cerr << "his grade is " << getGrade() << std::flush;
		std::cerr << " and form grade is " << form.getReqToSign() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bure) {
	os << bure.getName() << ", bureaucrat grade " << bure.getGrade() << ".";
	return (os);
}
