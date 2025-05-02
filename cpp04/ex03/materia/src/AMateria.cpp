/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:20:32 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/16 09:47:41 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria()
:	type("")
{}

AMateria::~AMateria()
{}

AMateria::AMateria(const AMateria &other)
:	type(other.type)
{}

AMateria	&AMateria::operator=(const AMateria &other) {
	static_cast<void>(other);
	return (*this);
}

AMateria::AMateria(std::string const &type)
:	type(type)
{}

std::string const	&AMateria::getType() const {
	return (type);
}