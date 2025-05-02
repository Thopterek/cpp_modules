#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class	Animal {
	protected:
		std::string	type;
	public:
		Animal();
		/*
			always making the destructor in base virtual
			if there is dynamic memory or 'polymorphism'
			compile time with overloading or runtime virtual
		*/
		virtual ~Animal();
		Animal(const Animal &other);
		Animal	&operator=(const Animal &other);
		/*
				make sound function
			(virtual gets overwritten)
			plus getters and setters
		*/
		virtual void	makeSound() const;
		std::string	getType() const;
		void	setType(const std::string set_type);
};

#endif