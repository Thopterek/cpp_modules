#ifndef	ICHARACTER_HPP
#define	ICHARACTER_HPP

#include <iostream>

/*
	forward declaration for AMateria
	to fix the cyclical includes
*/
class AMateria;

/*
	Pure virtual class
	breaking the OC form
*/
class ICharacter {
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

#endif