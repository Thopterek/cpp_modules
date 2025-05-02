/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:51:30 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/16 15:56:59 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character()
:	name(""), capacity(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(std::string new_name)
:	name(new_name), capacity(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(const Character &other)
:	name(other.name), capacity(other.capacity)
{
	for (int i = 0; i < getCapacity(); i++)
		this->inventory[i] = other.inventory[i]->clone();
}

Character	&Character::operator=(const Character &other) {
	if (this != &other) {
		for (int i = 0; i < getCapacity(); i++)
			delete inventory[i];
	}
	Character	tmp(other);
	std::swap(name, tmp.name);
	std::swap(capacity, tmp.capacity);
	if (this != &other) {
		for (int i = 0; i < getCapacity(); i++)
			this->inventory[i] = other.inventory[i]->clone();
	}
	return (*this);
}

/*
	subject related functions
	TB mandatory implemented
*/
Character::~Character() {
	for (int i = 0; i < getCapacity(); i++)
		delete	inventory[i];
}

std::string	const &Character::getName() const {
	return (name);
}

void	Character::equip(AMateria *m) {
	if (getCapacity() == 4) {
		std::cout << "can't equip more" << std::endl;
		Floor::setFloorNext(m);
		return ;
	}
	inventory[getCapacity()] = m;
	setCapacity(getCapacity() + 1);
}

void	Character::unequip(int idx) {
	if (getCapacity() <= idx || idx < 0)
		return ;
	Floor::setFloorNext(inventory[idx]);
	inventory[idx] = 0;
	for (int i = idx; i < getCapacity() - 1; i++) {
		inventory[i] = inventory[i + 1];
	}
	inventory[getCapacity() - 1] = 0;
	setCapacity(getCapacity() - 1);
}

void	Character::use(int idx, ICharacter &target) {
	if (getCapacity() <= idx || idx < 0) {
		std::cout << "Character::use outside of index scope" << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}

/*
	Setters and getters
	all per the header
*/
void	Character::setName(std::string new_name) {
	name = new_name;
}

void	Character::setCapacity(int total) {
	capacity = total;
}

int	Character::getCapacity() const {
	return (capacity);
}

AMateria	*Character::getItem(int index) const {
	return (inventory[index]);
}

Character::Character(const ICharacter &other)
{
	const Character	*tmp = dynamic_cast<const Character*>(&other);
	name = tmp->getName();
	capacity = tmp->getCapacity();
	for (int i = 0; i < getCapacity(); i++)
		this->inventory[i] = tmp->inventory[i]->clone();
}

Character	&Character::operator=(const ICharacter &other) {
	const Character	*tmp = dynamic_cast<const Character*>(&other);
	for (int i = 0; i < getCapacity(); i++)
		delete inventory[i];
	name = tmp->name;
	capacity = tmp->capacity;
	for (int i = 0; i < getCapacity(); i++)
		this->inventory[i] = tmp->inventory[i]->clone();
	return (*this);
}