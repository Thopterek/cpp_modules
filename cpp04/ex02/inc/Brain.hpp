#ifndef	BRAIN_HPP
#define	BRAIN_HPP

#include <iostream>

class	Brain {
	private:
		std::string	ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain	&operator=(const Brain &other);
		void	setIdea(int which, std::string idea);
		std::string	getIdea(int which) const;
};

#endif