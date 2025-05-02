/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:00:09 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 12:03:24 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

/*
	Copy pase code from subject:
	- deleted non changing {}
	- added numbers to clubs
*/
int	main() {
	Weapon	club = Weapon("crude spiked club");
	HumanA	bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	Weapon	club2 = Weapon("another crude spiked club");
	HumanB	jim("Jim");
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("way newer spiked club");
	jim.attack();
	return (0);
}