/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:49:28 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 10:04:24 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

// void leaks() {
// 	system("leaks brainz");
// }
// atexit(leaks);

int	main(void) {
	std::cout << "Creating a Zombie" << std::endl;
	Zombie	first("My_name_is_first_with_underscores");
	std::cout << "There is no other message because its normal one" << std::endl;
	first.announce();
	std::cout << "I used member function announce on him" << std::endl;
	Zombie	*second = newZombie("2_NUMBER_TWO_THATS_MY_NAME");
	std::cout << "made second using the newZombie function (to be deleted)" << std::endl;
	(*second).announce();
	std::cout << "second announced himself to everyone, now will the third" << std::endl;
	randomChump("T H I R D  Z0o0ombie");
	std::cout << "Okay that's all, now I will delete the second one" << std::endl;
	delete second;
	std::cout << "the destructors are being called when they go out of scope anyway" << std::endl;
	return (0);
}
