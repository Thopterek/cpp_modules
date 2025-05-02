/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:16:32 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 10:29:51 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/*
	Using new placement (is it optimization?)
	- single allocation for chunk of memory
	<no repeated calls to the new>
	<contagious memory allocation>
	<lower memory overhead (no extra ptr)>
	- static_casting rather than the one from c
	- constructs in pre alllocated memory
		(constructing in place)
*/
Zombie	*zombieHorde(int n, std::string name) {
	void	*buf = operator new[](n * sizeof(Zombie));
	Zombie	*horde = static_cast<Zombie*>(buf);
	for (int i = 0; i < n; i++)
		new (&horde[i]) Zombie(name);
	return (horde);
}

/*
	Manual construction of object means:
	- manual deconstruction on them
	- deleteing the raw memory (prev. buf)
*/
void	byeByeHorde(int n, Zombie *horde) {
	for (int i = 0; i < n; i++)
		horde[i].~Zombie();
	operator delete[](horde);
}
