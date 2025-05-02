#ifndef	SCAVTRAP_HPP
#define	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap	&operator=(const ScavTrap &other);
		/*
			new function that only ScavTrap has
			plus the new message from attack
		*/
		void	guardGate();
		void	attack(const std::string &target);
};

#endif