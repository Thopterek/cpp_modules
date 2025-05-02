#ifndef	DIAMONDTRAP_HPP
#define	DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

/*
	Code class B: virtual A means:
	that any class inherited from B
	is now responsible for creating A by itself
	since B isn't going to do it automatically
*/
class	DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap	&operator=(const DiamondTrap &other);
		/*
				whoAmI and the attack
			 warning: access declarations are deprecated
			 so you need to use the keyword using
		*/
		void	whoAmI();
		using	ScavTrap::attack;
};

#endif