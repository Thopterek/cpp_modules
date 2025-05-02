/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:57:06 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/14 10:27:10 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog()
:	Animal()
{
	setType("Dog");
	std::cout << "DOGGY default constructor being used" << std::endl;
}

Dog::~Dog()
{
	std::cout << "DOGGY deconstructor on the call" << std::endl;
}

Dog::Dog(const Dog &other)
:	Animal()
{
	type = other.getType();
	std::cout << "DOGGY copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other) {
	Dog	tmp(other);
	std::swap(type, tmp.type);
	std::cout << "DOGGY copy assingment operator" << std::endl;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "DOGGY says: put your hands behind your back" << std::endl;
}