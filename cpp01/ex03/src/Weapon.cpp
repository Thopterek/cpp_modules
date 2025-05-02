/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:56:32 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 12:00:02 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

Weapon::Weapon()
:	type("")
{}

Weapon::~Weapon()
{}

Weapon::Weapon(const Weapon &other)
:	type(other.type)
{}

Weapon	&Weapon::operator=(const Weapon &other) {
	Weapon	tmp(other);
	std::swap(type, tmp.type);
	return (*this);
}

const std::string	&Weapon::getType() {
	return (type);
}

void	Weapon::setType(std::string new_value) {
	type = new_value;
}

Weapon::Weapon(std::string new_value) {
	(*this).setType(new_value);
}
