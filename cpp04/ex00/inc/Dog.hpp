#ifndef	DOG_HPP
#define	DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal {
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);
		/*
			C++11 and later would be:
			void	makeSound() const override;
		*/
		void	makeSound()const;
};

#endif