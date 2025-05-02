#ifndef	BASE_HPP
#define	BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class	Base {
	public:
		virtual ~Base();
};

/*
	Randomly instantiates A, B or C
	and returns the pointer to instance
*/
Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif