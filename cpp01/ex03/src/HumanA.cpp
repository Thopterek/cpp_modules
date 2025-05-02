/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:48:45 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 12:04:05 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

HumanA::~HumanA()
{}

HumanA::HumanA(const HumanA &other)
:	name(other.name), weapon(other.weapon)
{}

HumanA	&HumanA::operator=(const HumanA &other) {
	HumanA	tmp(other);
	std::swap(name, tmp.name);
	std::swap(weapon, tmp.weapon);
	return (*this);
}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
:	name(name), weapon(weapon)
{}