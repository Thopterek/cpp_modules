#ifndef	CURE_HPP
#define	CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	protected:
		std::string	type;
	public:
		Cure();
		~Cure();
		Cure(const Cure &other);
		Cure	&operator=(const Cure &other);
		/*
			Subject copy pase
			above the OC form
		*/
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif