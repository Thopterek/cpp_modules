/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:38:00 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/10 09:21:26 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int	main() {
	std::cout << std::string(55, '#') << std::endl;
	std::cout << "We are starting with creating a ClapTrap named Bobby" << std::endl;
	std::cout << std::string(55, '#') << std::endl;
	ClapTrap	bobby("Bobby");
	std::cout << "he is going to attack the dummy target string named Enemy" << std::endl;
	const std::string target = "Enemy";
	bobby.attack(target);
	std::cout << "now he is going to try and repeat it on John" << std::endl;
	bobby.attack("John");
	std::cout << "time to heal himself from all the trauma he did on others" << std::endl;
	bobby.beRepaired(1);
	std::cout << "after that he chose to take some damage, 5 to be exact" << std::endl;
	bobby.takeDamage(5);
	std::cout << "he will heal himself for 3 life" << std::endl;
	bobby.beRepaired(3);
	std::cout << "and keep attacking until he has no energy left" << std::endl;
	for (int i = 0; i < 7; i++)
		bobby.attack(target);
	std::cout << std::string(55, '#') << std::endl;
	std::cout << "there is also another ClapTrap name David" << std::endl;
	std::cout << std::string(55, '#') << std::endl;
	ClapTrap	david("David");
	std::cout << "he took 10000 damage at start" << std::endl;
	david.takeDamage(10000);
	std::cout << "he wanted to heal himself for 9 and attack Player" << std::endl;
	david.beRepaired(9);
	david.attack("Player");
	return (0);
}