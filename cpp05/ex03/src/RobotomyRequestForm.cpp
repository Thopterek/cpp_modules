/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:38:24 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/22 14:36:02 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
:	AForm("RobotomyRequestForm", 72, 45), target("")
{
	std::cout << "RRF default constructor, most likely never called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string set_target)
:	AForm("RobotomyRequestForm", 72, 45), target(set_target)
{
	std::cout << "RRF construtor with name per subject" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RRF destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
:	AForm(other), target(other.target)
{
	std::cout << "RRF copy constructor" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		target = other.getTarget();
	}
	std::cout << "RRF copy assingment operator" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::action() const {
	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
	std::cout << "* those were drilling noises *" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2) {
		std::cout << "Robotomy on " << getTarget() << " done succesfully" << std::endl;
	}
	else
		std::cout << "Robotomy on " << getTarget() << " failed" << std::endl;
	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
}

std::string const	&RobotomyRequestForm::getTarget() const {
	return (target);
}

AForm	*RobotomyRequestForm::newRobotomy(std::string set_target) {
	return (new RobotomyRequestForm(set_target));
}