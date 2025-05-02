/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:49:28 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 10:29:36 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

// void leaks() {
// 	system("leaks moar_brainz");
// }
// atexit(leaks);

int	main(void) {
	std::cout << "Creating a Zombie" << std::endl;
	Zombie	first("My_name_is_first_with_underscores");
	std::cout << "There is no other message because its normal one" << std::endl;
	first.announce();
	std::cout << "I used member function announce on him" << std::endl;
	Zombie	*horde = zombieHorde(9, "Bobby");
	std::cout << "Now I created a horde of Zombies, each named Bobby" << std::endl;
	horde[0].announce();
	std::cout << "First from the Bobby horde announced himself" << std::endl;
	for (int i = 1; i < 9; i++)
		horde[i].announce();
	std::cout << "and here came the Bobbies familly" << std::endl;
	byeByeHorde(9, horde);
	std::cout << "and now they said byebye (per function name)" << std::endl;
	std::cout << "the first one does it on his own" << std::endl;
	return (0);
}
