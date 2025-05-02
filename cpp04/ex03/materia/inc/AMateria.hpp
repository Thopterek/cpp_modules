#ifndef	AMATERIA_HPP
#define	AMATERIA_HPP

#include <iostream>
#include "../../character/inc/ICharacter.hpp"

/*
	abstract class
	mixed virtual functions
	with the normal
*/
class AMateria {
	protected:
		std::string type;
	public:
		AMateria();
		virtual	~AMateria();
		AMateria(const AMateria &other);
		AMateria	&operator=(const AMateria &other);
		/*
			OC form above
			below subject
		*/
		AMateria(std::string const &type);
		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target) = 0;
};

#endif