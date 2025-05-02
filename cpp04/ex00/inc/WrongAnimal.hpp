#ifndef	WRONGANIMAL_HPP
#define	WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal	&operator=(const WrongAnimal &other);
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