/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:14:46 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/14 13:41:43 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat()
:	WrongAnimal()
{
	brain = new Brain();
	setType("WrongCat");
	std::cout << "wRoNg-cat default constructor being used" << std::endl;
}

WrongCat::~WrongCat()
{
	delete	brain;
	std::cout << "wRoNg-cat deconstructor on the call" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
:	WrongAnimal()
{
	type = other.getType();
	std::cout << "wRoNg-cat copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other) {
	WrongCat	tmp(other);
	std::swap(type, tmp.type);
	std::cout << "WrOnG-cat copy assingment operator" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "wRoNg-CaT says: w r o n g cat WRONG" << std::endl;
}