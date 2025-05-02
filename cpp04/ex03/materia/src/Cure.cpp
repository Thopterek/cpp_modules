/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:14:24 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/16 10:00:35 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure()
:	AMateria("cure"), type("cure")
{}

Cure::~Cure()
{}

Cure::Cure(const Cure &other)
:	AMateria(other.type), type(other.type)
{}

Cure	&Cure::operator=(const Cure &other) {
	Cure	tmp(other);
	std::swap(type, tmp.type);
	return (*this);
}

AMateria	*Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}