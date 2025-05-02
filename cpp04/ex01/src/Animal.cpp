/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:29:54 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/14 10:31:34 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal()
:	type("")
{
	std::cout << "Animal default constructor being used" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor on the call" << std::endl;
}

Animal::Animal(const Animal &other)
:	type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &other) {
	Animal	tmp(other);
	std::swap(type, tmp.type);
	std::cout << "Animal copy assingment operator" << std::endl;
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "Animal random sounds AAAAAAAAAA" << std::endl;
}

std::string	Animal::getType() const {
	return (type);
}

void	Animal::setType(const std::string set_type)
{
	type = set_type;
}