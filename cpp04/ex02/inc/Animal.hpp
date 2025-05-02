#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

/*
	making it an abstrac class
	because there is no definition for ft
	in this case for virtual makeSound(),
	it needs one pure virtual function
*/
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
		virtual void	makeSound() const = 0;
		std::string	getType() const;
		void	setType(const std::string set_type);
};

#endif