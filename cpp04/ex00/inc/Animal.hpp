#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP

#include <iostream>

class	Animal {
	protected:
		std::string	type;
	public:
		Animal();
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