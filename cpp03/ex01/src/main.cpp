/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:38:00 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/10 12:18:36 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

int	main() {
	std::cout << std::string(55, '#') << std::endl;
	std::cout << "We are starting with creating a ClapTrap named Bobby" << std::endl;
	std::cout << std::string(55, '#') << std::endl;
	ClapTrap	bobby("Bobby");
	bobby.attack("someone");
	bobby.takeDamage(7);
	bobby.beRepaired(1);
	std::cout << std::string(55, '#') << std::endl;
	std::cout << "but now we are creating a ScavTrap Jeremy and his brother" << std::endl;
	std::cout << "we will have to name him, as his parents picked the name later" << std::endl;
	std::cout << std::string(55, '#') << std::endl;
	ScavTrap	jeremy("Jeremy");
	ScavTrap	brother;
	brother.setName("Lil_bro");
	jeremy.takeDamage(22);
	brother.takeDamage(78);
	jeremy.beRepaired(10);
	brother.beRepaired(1);
	jeremy.guardGate();
	brother.guardGate();
	jeremy.attack("Target_Dummy");
	brother.attack("Target_Dummy");
	std::cout << std::string(55, '#') << std::endl;
	std::cout << "Okay enough testing now destructors should be called" << std::endl;
	std::cout << "Double for both Scrap Traps and once for the normal" << std::endl;
	std::cout << std::string(55, '#') << std::endl;
	return (0);
}