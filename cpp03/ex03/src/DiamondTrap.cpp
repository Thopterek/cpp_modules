/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:57:02 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/11 10:27:46 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap(), ScavTrap(), FragTrap(), name("") {
	FragTrap	frag;
	ScavTrap	scav;
	DiamondTrap::setName("_clap_name");
	DiamondTrap::setHitPoints(frag.getHitPoints());
	DiamondTrap::setMaxHp(frag.getHitPoints());
	DiamondTrap::setEnergy(scav.getEnergy());
	DiamondTrap::setAttackDmg(frag.getAttackDmg());
	std::cout << "DiamondTrap defult constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
	std::cout << std::string(80, '!') << std::endl;
	std::cout << "WARNING: ClapTrap constructors below got called for temporary not for Diamond" << std::endl;
	std::cout << std::string(80, '!') << std::endl;
	FragTrap	frag;
	ScavTrap	scav;
	DiamondTrap::setHitPoints(frag.getHitPoints());
	DiamondTrap::setMaxHp(frag.getHitPoints());
	DiamondTrap::setEnergy(scav.getEnergy());
	DiamondTrap::setAttackDmg(frag.getAttackDmg());
	std::cout << std::string(40, '.') << std::endl;
	std::cout << "DiamondTrap constructor with name" << std::endl;
	std::cout << std::string(40, '.') << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DIAMOND I REPEAT: DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
:	ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other) {
	ClapTrap::operator=(other);
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is " << this->name << std::flush;
	std::cout << " and the ClapTrap name is " << ClapTrap::getName() << std::endl;
}