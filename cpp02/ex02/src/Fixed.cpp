/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:01:56 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 20:05:45 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed()
:	raw(0)
{}
/*
	non default constructors
	int and float
*/
Fixed::Fixed(const int fixed)
:	raw(fixed << bits)
{}

Fixed::Fixed(const float fixed) {
	raw = static_cast<int>(roundf(fixed * (1 << bits)));
}

Fixed::~Fixed() 
{}

Fixed::Fixed(const Fixed &other)
:	raw(other.raw)
{}

Fixed	&Fixed::operator=(const Fixed &other) {
	Fixed	tmp(other);
	std::swap(raw, tmp.raw);
	return (*this);
}

/*
	getter and setter
*/
int	Fixed::getRawBits(void) const {
	return (raw);
}

void	Fixed::setRawBits(int const raw) {
	this->raw = raw;
}

/*
		conversions
	to float & to int
*/
int	Fixed::toInt(void) const {
	return (raw >> bits);
}

float	Fixed::toFloat(void) const {
	const float scale_factor = 1.0f / (1 << bits);
	return (static_cast<float>(raw) * scale_factor);
}

/*
	bool operators
*/
bool	Fixed::operator>(const Fixed &other) const {
	return (this->raw > other.raw);
}

bool	Fixed::operator<(const Fixed &other) const {
	return (this->raw < other.raw);
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->raw >= other.raw);
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (this->raw <= other.raw);
}

bool	Fixed::operator==(const Fixed &other) const {
	return (this->raw == other.raw);
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->raw != other.raw);
}

/*
	substraction and sum
	both version pre/post
*/
Fixed	&Fixed::operator++() {
	return (this->raw += 1, *this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	return (this->raw += 1, tmp);
}

Fixed	&Fixed::operator--() {
	return (this->raw -= 1, *this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	return (this->raw -= 1, tmp);
}

/*
	helper functions for min and max
*/
Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return ((a < b) ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return ((a < b) ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return ((a > b) ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return ((a > b) ? a : b);
}

/*
	math operations + os
*/
Fixed	operator+(const Fixed &a, const Fixed &b) {
	return (Fixed(a.toFloat() + b.toFloat()));
}

Fixed	operator-(const Fixed &a, const Fixed &b) {
	return (Fixed(a.toFloat() - b.toFloat()));
}

Fixed	operator*(const Fixed &a, const Fixed &b) {
	return (Fixed(a.toFloat() * b.toFloat()));
}

Fixed	operator/(const Fixed &a, const Fixed &b) {
	return (Fixed(a.toFloat() / b.toFloat()));
}

std::ostream	&operator<<(std::ostream& os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}