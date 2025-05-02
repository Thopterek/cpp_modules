#ifndef	ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class	Zombie {
	private:
		std::string	name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		Zombie(const Zombie	&other);
		Zombie	&operator=(const Zombie	&other);
		void	announce(void);
};

Zombie	*zombieHorde(int n, std::string name);
void	byeByeHorde(int n, Zombie *horde);

#endif