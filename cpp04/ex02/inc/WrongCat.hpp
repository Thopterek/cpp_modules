#ifndef	WRONGCAT_HPP
#define	WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	private:
		Brain	*brain;
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat	&operator=(const WrongCat &other);
		/*
			C++11 and later would be:
			void	makeSound() const override;
		*/
		void	makeSound()const;
};

#endif