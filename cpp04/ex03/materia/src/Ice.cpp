/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:55:06 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/16 11:04:41 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice()
:	AMateria("ice"), type("ice")
{}

Ice::~Ice()
{}

Ice::Ice(const Ice &other)
:	AMateria(other.type), type(other.type)
{}

Ice	&Ice::operator=(const Ice &other) {
	Ice	tmp(other);
	std::swap(type, tmp.type);
	return (*this);
}

AMateria	*Ice::clone() const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}