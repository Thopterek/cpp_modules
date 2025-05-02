#ifndef	FLOOR_HPP
#define	FLOOR_HPP

#include "../../materia/inc/AMateria.hpp"

class	Floor {
	private:
		static int	size;
		static AMateria	*on_floor[100];
	public:
		Floor();
		~Floor();
		Floor(const Floor &other);
		Floor	&operator=(const Floor &other);
		/*
			above OC form needed per rule
			below getters and setters
			all static for static members
		*/
		static int	getSize();
		static void	setSize(int new_size);
		static AMateria	*getOnFloorByIndex(int index);
		static void	setFloorNext(AMateria *target);
		static void	cleanFloor();
};

#endif