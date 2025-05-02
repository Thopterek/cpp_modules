/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:53:31 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 12:04:38 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

/*
	adding ctypes or using a newer version can replace
	the below 0 thats is used for the std 98 that I have
*/
HumanB::HumanB()
:	name(""), weapon(0)
{}

HumanB::~HumanB()
{}

HumanB::HumanB(const HumanB &other)
:	name(other.name), weapon(other.weapon)
{}

HumanB	&HumanB::operator=(const HumanB &other) {
	HumanB	tmp(other);
	std::swap(name, tmp.name);
	std::swap(weapon, tmp.weapon);
	return (*this);
}

void	HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name)
:	name(name), weapon(0)
{}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
