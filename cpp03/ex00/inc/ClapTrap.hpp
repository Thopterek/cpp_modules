#ifndef	CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>

class	ClapTrap {
	private:
		std::string	name;
		unsigned int	hit_points;
		unsigned int	energy;
		unsigned int	attack_dmg;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap	&operator=(const ClapTrap &other);
		/*
			member functions
			for behaviour
		*/
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif