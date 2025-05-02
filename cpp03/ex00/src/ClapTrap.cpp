/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:40:37 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/30 16:15:23 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap()
:	name(""), hit_points(10), energy(10), attack_dmg(0)
{
	std::cout << "Default constructor got called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
:	name(name), hit_points(10), energy(10), attack_dmg(0)
{
	std::cout << "Constructor with name got called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor got called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
:	name(other.name), hit_points(other.hit_points),
	energy(other.energy), attack_dmg(other.attack_dmg)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	ClapTrap	tmp(other);
	std::swap(name, tmp.name);
	std::swap(hit_points, tmp.hit_points);
	std::swap(energy, tmp.energy);
	std::swap(attack_dmg, tmp.attack_dmg);
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (energy <= 0 || hit_points <= 0) {
		std::cout << "ClapTrap " << name << std::flush;
		std::cout << " tried to attack " << target << std::flush;
		std::cout << ", but has no life or energy" << std::endl;
	}
	else {
		energy -= 1;
		std::cout << "ClapTrap " << name << std::flush;
		std::cout << " attacks " << target << std::flush;
		std::cout << ", causing " << attack_dmg << std::flush;
		std::cout << " points of damage to " << target << std::flush;
		std::cout << ", and has " << energy << " energy left" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > 10 || hit_points - amount < 0)
		hit_points = 0;
	else
		hit_points -= amount;
	std::cout << "ClapTrap " << name << std::flush;
	std::cout << " took " << amount << std::flush;
	std::cout << " amount of damage" << std::flush;
	std::cout << " and has " << hit_points << std::flush;
	std::cout << " total life" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (energy <= 0 || hit_points <= 0) {
		std::cout << "ClapTrap " << name << std::flush;
		std::cout << " tried to repair himself, but" << std::flush;
		std::cout << " has no life or energy" << std::endl;
	}
	else {
		energy -= 1;
		if (amount + hit_points >= 10 || amount >= 10) {
			hit_points = 10;
			std::cout << "ClapTrap " << name << std::flush;
			std::cout << " healed over the top for " << amount << std::flush;
			std::cout << ", now at the max life " << hit_points << std::flush;
			std::cout << ", and has " << energy << " energy left" << std::endl;
		}
		else {
			hit_points += amount;
			std::cout << "ClapTrap " << name << std::flush;
			std::cout << " healed for " << amount << std::flush;
			std::cout << ", now at life " << hit_points << std::flush;
			std::cout << ", and has " << energy << " energy left" << std::endl;
		}
	}
}