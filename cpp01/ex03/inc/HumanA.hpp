#ifndef	HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

class	HumanA {
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		/*
			No default constructor
			breaking the rule of orthodox
			but he alwas has to have a weapon
		*/
		~HumanA();
		HumanA(const HumanA &other);
		HumanA	&operator=(const HumanA &other);
		void	attack();
		HumanA(std::string name, Weapon &weapon);
};

#endif