/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:38:05 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 10:01:29 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie()
:	name("")
{}

Zombie::Zombie(std::string name)
:	name(name)
{}

Zombie::~Zombie() {
	std::cout << name << ": died" << std::endl;
}

Zombie::Zombie(const Zombie &other)
:	name(other.name)
{}

Zombie	&Zombie::operator=(const Zombie	&other) {
	Zombie	tmp(other);
	std::swap(name, tmp.name);
	return (*this);
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
