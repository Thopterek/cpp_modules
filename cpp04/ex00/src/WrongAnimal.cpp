/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:14:44 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/14 11:25:07 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
:	type("")
{
	std::cout << "WrongAnimal default constructor being used W R O N G" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor on the call W R O N G" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
:	type(other.type)
{
	std::cout << "WrongAnimal copy constructor called W R O N G" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other) {
	WrongAnimal	tmp(other);
	std::swap(type, tmp.type);
	std::cout << "WrongAnimal copy assingment operator W R O N G" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal says: thats really W R O N G" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (type);
}

void	WrongAnimal::setType(const std::string set_type)
{
	type = set_type;
}