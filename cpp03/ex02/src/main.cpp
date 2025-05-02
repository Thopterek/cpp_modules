/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:38:00 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/10 12:41:24 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int	main() {
	std::cout << std::string(55, '#') << std::endl;
	std::cout << "We are starting with creating a ClapTrap named Bobby" << std::endl;
	std::cout << std::string(55, '#') << std::endl;
	ClapTrap	bobby("Bobby");
	bobby.attack("someone");
	bobby.takeDamage(7);
	bobby.beRepaired(1);
	std::cout << std::string(55, '#') << std::endl;
	std::cout << "but now we are creating a ScavTrap Jeremy" << std::endl;
	std::cout << std::string(55, '#') << std::endl;
	ScavTrap	jeremy("Jeremy");
	jeremy.attack("Target_Dummy");
	jeremy.takeDamage(22);
	jeremy.beRepaired(10);
	jeremy.guardGate();
	std::cout << std::string(55, '#') << std::endl;
	std::cout << "there is the new type FragTrap Ducky" << std::endl;
	std::cout << std::string(55, '#') << std::endl;
	FragTrap	ducky("Ducky");
	ducky.attack("enemy of my enemy");
	ducky.takeDamage(99);
	ducky.beRepaired(11);
	std::cout << "it asks for high five, five times" << std::endl;
	for (int i = 0; i < 5; i++)
		ducky.highFivesGuys();
	std::cout << std::string(55, '#') << std::endl;
	std::cout << "Okay enough testing now destructors should be called" << std::endl;
	std::cout << "Double for ScrapTrap and FragTrap and once for the normal" << std::endl;
	std::cout << std::string(55, '#') << std::endl;
	return (0);
}