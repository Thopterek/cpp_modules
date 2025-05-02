/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:09:27 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 13:29:05 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

Harl::Harl(const Harl &other)
{}

Harl	&Harl::operator=(const Harl &other) {
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
*/
void	Harl::complain(std::string level) {
	void	(Harl::*lvl[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	volume[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (volume[i].compare(level) == 0) {
			(this->*lvl[i])();
			return ;
		}
	}
	std::cerr << "HELLO: you went above and beyond of Harl" << std::endl;
}