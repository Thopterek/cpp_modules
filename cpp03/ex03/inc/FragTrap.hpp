#ifndef	FRAGTRAP_HPP
#define	FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap	&operator=(const FragTrap &other);
		/*
			new function that only FragTrap has
				the highFivesGuys
		*/
		void	highFivesGuys(void);
};

#endif