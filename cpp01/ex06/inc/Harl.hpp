#ifndef	HARL_HPP
#define	HARL_HPP

#include <iostream>
#include <string>

class	Harl {
	private:
		std::string	input;
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
	public:
		Harl();
		Harl(std::string input);
		~Harl();
		Harl(const Harl &other);
		Harl	&operator=(const Harl &other);
		void	complain(void);
};

#endif