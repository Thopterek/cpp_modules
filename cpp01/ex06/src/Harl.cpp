/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:09:27 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 13:30:52 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{}

Harl::Harl(std::string input)
:	input(input)
{}

Harl::~Harl()
{}

Harl::Harl(const Harl &other)
:	input(other.input)
{}

Harl	&Harl::operator=(const Harl &other) {
	Harl	tmp(other);
	std::swap(input, tmp.input);
	return (*this);
}

void	Harl::debug(void) {
	std::cout << "DEBUG: I love having extra... blablabla" << std::endl;
}

void	Harl::info(void) {
	std::cout << "INFO: I cannot believe adding extra bacon costs.." << std::endl;
}

void	Harl::warning(void) {
	std::cout << "WARNING: I think I deserve to have some..." << std::endl;
}

void	Harl::error(void) {
	std::cout << "ERROR: I want to speak to the manager!!!" << std::endl;
}

/*
	creating pointers to functions above
		calling it with *lvl[i]
	I also made the change to complain
	just to make it easier for myself
	its easy fix to revert to other one
	but we need a new function for ex06
*/
void	Harl::complain(void) {
	void	(Harl::*lvl[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	volume[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	filter = 4;
	for (int i = 0; i < 4; i++) {
		if (input.compare(volume[i]) == 0) {
			filter = i;
			break ;
		}
	}
	switch (filter) {
		case (0):
			(this->*lvl[0])();
		case (1):
			(this->*lvl[1])();
		case (2):
			(this->*lvl[2])();
		case (3):
			(this->*lvl[3])();
			break ;
		default:
			std::cout << "HELLO: you went above and beyond of Harl" << std::endl;
	}
}