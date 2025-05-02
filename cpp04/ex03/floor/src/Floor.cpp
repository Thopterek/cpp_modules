/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:21:05 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/16 14:29:33 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Floor.hpp"

AMateria	*Floor::on_floor[100] = {0};
int	Floor::size = 0;

Floor::Floor()
{}

Floor::~Floor() {
	for (int i = 0; i < getSize(); i++)
		delete	on_floor[i];
}

Floor::Floor(const Floor &other)
{
	this->size = other.getSize();
	setSize(other.getSize());
	for (int i = 0; i < other.getSize(); i++)
		on_floor[i] = other.on_floor[i];
}

Floor	&Floor::operator=(const Floor &other) {
	Floor tmp(other);
	std::swap(size, tmp.size);
	for (int i = 0; i < getSize(); i++)
		std::swap(on_floor[i], tmp.on_floor[i]);
	return (*this);
}

int	Floor::getSize() {
	return (size);
}

void	Floor::setSize(int new_size) {
	size = new_size;
}

AMateria	*Floor::getOnFloorByIndex(int index) {
	return (on_floor[index]);
}

void	Floor::setFloorNext(AMateria *target) {
	if (getSize() == 100)
		return ;
	on_floor[getSize()] = target;
	setSize(getSize() + 1);
}

void	Floor::cleanFloor() {
	for (int i = 0; i < getSize(); i++) {
		std::cout << "Cleaned AMateria number: " << i << std::endl;
		delete on_floor[i];
	}
}