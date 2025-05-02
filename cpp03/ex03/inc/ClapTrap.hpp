#ifndef	CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>

class	ClapTrap {
	private:
		unsigned int	max_hp;
		/*
			above extra informaiton
			below the subject ones
		*/
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
		/*
			getters and setters for private vars
			and constructor that initializes all
		*/
		std::string	getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergy() const;
		unsigned int	getAttackDmg() const;
		unsigned int	getMaxHp() const;
		void	setName(std::string name);
		void	setHitPoints(unsigned int value);
		void	setEnergy(unsigned int value);
		void	setAttackDmg(unsigned int value);
		void	setMaxHp(unsigned int value);
		ClapTrap(std::string n, unsigned int hit, unsigned int ene, unsigned int dmg);
};

#endif