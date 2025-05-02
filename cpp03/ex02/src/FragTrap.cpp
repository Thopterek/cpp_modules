/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:25:55 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/11 10:18:38 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap()
:	ClapTrap()
{
	setName("");
	setHitPoints(100);
	setEnergy(100);
	setAttackDmg(30);
	setMaxHp(getHitPoints());
	std::cout << "FragTrap default constructor got called" << std::endl;
}

FragTrap::FragTrap(std::string name)
:	ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor with name got called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor got called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) 
:	ClapTrap(other)
{
	std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator" << std::endl;
	ClapTrap::operator=(other);
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << getName() << " is asking for high five" << std::endl;
}