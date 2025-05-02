#ifndef	CAT_HPP
#define	CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal {
	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat	&operator=(const Cat &other);
		/*
			C++11 and later would be:
			void	makeSound() const override;
		*/
		void	makeSound()const;
};

#endif