#ifndef	MATERIASOURCE_HPP
#define	MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		int	capacity;
		AMateria	*known[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource	&operator=(const MateriaSource &other);
		/*
			subject related below
			and above the OC form
		*/
		~MateriaSource();
		void learnMateria(AMateria *type);
		AMateria	*createMateria(std::string const &type);
		/*
			getters and setters
			for private members
		*/
		int	getCapacity() const;
		AMateria	*getKnown(int idx) const;
		void	setCapacity(int cap);
};

#endif