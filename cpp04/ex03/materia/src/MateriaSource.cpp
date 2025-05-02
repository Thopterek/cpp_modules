/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:51:39 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/16 14:27:16 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource()
:	capacity(0)
{
	for (int i = 0; i < 4; i++)
		known[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
:	capacity(other.capacity)
{
	for (int i = 0; i < getCapacity(); i++)
		this->known[i] = other.known[i]->clone();
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < getCapacity(); i++)
			delete known[i];
	}
	MateriaSource	tmp(other);
	std::swap(capacity, tmp.capacity);
	std::swap(known, tmp.known);
	if (this != &other) {
		for (int i = 0; i < getCapacity(); i++)
			this->known[i] = other.known[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < getCapacity(); i++)
		delete	known[i];
}

void	MateriaSource::learnMateria(AMateria *type) {
	if (getCapacity() == 4) {
		std::cout << "hit the maximum capacity for learning, materia dropped on Floor" << std::endl;
		Floor::setFloorNext(type);
		return ;
	}
	else {
		known[getCapacity()] = type;
		setCapacity(getCapacity() + 1);
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < getCapacity(); i++) {
		if (type == known[i]->getType()) {
			return (known[i]->clone());
		}
	}
	std::cout << "Couldn't create a Materia" << std::endl;
	return (0);
}

int	MateriaSource::getCapacity() const {
	return (capacity);
}

AMateria	*MateriaSource::getKnown(int idx) const {
	if (idx >= getCapacity() || idx < 0)
		return (0);
	else
		return (known[idx]);
}

void	MateriaSource::setCapacity(int cap) {
	capacity = cap;
}