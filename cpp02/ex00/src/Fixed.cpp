/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:01:56 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 16:08:24 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed()
:	raw(0)
{
	std::cout << "DEFAULT: called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "DESTRUCTOR: said bye" << std::endl;
}

Fixed::Fixed(const Fixed &other)
:	raw(other.raw)
{
	std::cout << "COPY: yanked" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &other) {
	Fixed	tmp(other);
	std::swap(raw, tmp.raw);
	std::cout << "ASSIGN OPERATOR: took the value" << std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "GET RAW BITS" << std::endl;
	return (raw);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "SET RAW BITS" << std::endl;
	this->raw = raw;
}
