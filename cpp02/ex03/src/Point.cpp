/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:25:22 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 20:40:35 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point()
:	x(0), y(0)
{}

Point::~Point()
{}

Point::Point(const Point &other)
:	x(other.x), y(other.y)
{}

Point	&Point::operator=(const Point &other) {
	static_cast<void>(other);
	return (*this);
}

Fixed	Point::getX() const {
	return (this->x);
}

Fixed	Point::getY() const {
	return (this->y);
}

Point::Point(const Fixed x, const Fixed y)
:	x(x), y(y)
{}