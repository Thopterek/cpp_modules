/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:43:21 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/14 10:27:23 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat()
:	Animal()
{
	setType("Cat");
	std::cout << "C A T default constructor being used" << std::endl;
}

Cat::~Cat()
{
	std::cout << "C A T deconstructor on the call" << std::endl;
}

Cat::Cat(const Cat &other)
:	Animal()
{
	type = other.getType();
	std::cout << "C A T copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other) {
	Cat	tmp(other);
	std::swap(type, tmp.type);
	std::cout << "C A T copy assingment operator" << std::endl;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "C A T says: m i a u  m i a u  m i a u" << std::endl;
}