/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:33:02 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/11 10:17:45 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap()
:	ClapTrap()
{
	setName("");
	setHitPoints(100);
	setEnergy(50);
	setAttackDmg(20);
	setMaxHp(getHitPoints());
	std::cout << "ScavTrap default constructor got called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
:	ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor with name got called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor got called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) 
:	ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator" << std::endl;
	ClapTrap::operator=(other);
	return (*this);
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " in the GATE KEEPER MODE" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (getEnergy() <= 0 || getHitPoints() <= 0) {
		std::cout << "ScavTrap " << getName() << std::flush;
		std::cout << " tried to attack " << target << std::flush;
		std::cout << ", but SCAVTRAP has no life or energy" << std::endl;
	}
	else {
		setEnergy(getEnergy() - 1);
		std::cout << "ScavTrap " << getName() << std::flush;
		std::cout << " attacks " << target << std::flush;
		std::cout << ", causing " << getAttackDmg() << std::flush;
		std::cout << " points of damage to " << target << std::flush;
		std::cout << ", and SCAVTRAP has " << getEnergy() << " energy left" << std::endl;
	}
}
