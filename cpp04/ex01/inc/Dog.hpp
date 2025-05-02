#ifndef	DOG_HPP
#define	DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal {
	private:
		Brain	*brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);
		/*
			C++11 and later would be:
			void	makeSound() const override;
		*/
		void	makeSound()const;
};

#endif