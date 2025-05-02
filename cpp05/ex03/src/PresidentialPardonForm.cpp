/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:08:41 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/22 14:27:19 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:	AForm("PresidentialPardonForm", 25, 5), target("")
{
	std::cout << "PPF default constructor, most likely never called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string set_target)
:	AForm("PresidentialPardonForm", 25, 5), target(set_target)
{
	std::cout << "PPF construtor with name per subject" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PPF destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
:	AForm(other), target(other.target)
{
	std::cout << "PPF copy constructor" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		target = other.getTarget();
	}
	std::cout << "PPF copy assingment operator" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::action() const {
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string const	&PresidentialPardonForm::getTarget() const {
	return (target);
}

AForm	*PresidentialPardonForm::newPresidential(std::string set_target) {
	return (new PresidentialPardonForm(set_target));
}