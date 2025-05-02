#ifndef	CHARACTER_HPP
#define	CHARACTER_HPP

#include "ICharacter.hpp"
#include "../../floor/inc/Floor.hpp"
#include "../../materia/inc/AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string	name;
		int	capacity;
		AMateria	*inventory[4];
	public:
		Character();
		Character(std::string new_name);
		Character(const Character &other);
		Character	&operator=(const Character &other);
		/*
			above the OC form (destructor below)
			+ added the constructor with name
			below the subject related ones
		*/
		~Character();
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		/*
			setters and getters
			for private members
			not made already above
		*/
		void	setName(std::string new_name);
		void	setCapacity(int	total);
		int	getCapacity() const;
		AMateria	*getItem(int	index) const;
		/*
			Extra clone like constructor members
			both taking the ICharacter for poly.
			and not modifying the ICharacer.hpp
		*/
		Character(const ICharacter &other);
		Character	&operator=(const ICharacter &other);
};

#endif