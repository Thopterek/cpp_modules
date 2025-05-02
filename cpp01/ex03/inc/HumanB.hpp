#ifndef	HUMAN_B_HPP
#define	HUMAN_B_HPP

#include "Weapon.hpp"

class	HumanB {
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB();
		~HumanB();
		HumanB(const HumanB &other);
		HumanB	&operator=(const HumanB &other);
		void	attack();
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
};

#endif