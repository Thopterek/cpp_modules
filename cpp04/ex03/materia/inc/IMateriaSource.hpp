#ifndef	IMATERIASOURCE_HPP
#define	IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include "../../floor/inc/Floor.hpp"
#include <iostream>

/*
	subject copy pase
	pure abstract class
*/
class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif