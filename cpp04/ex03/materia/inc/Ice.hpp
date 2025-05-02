#ifndef	ICE_HPP
#define	ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	protected:
		std::string	type;
	public:
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice	&operator=(const Ice &other);
		/*
			Subject copy pase
			above the OC form
		*/
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif