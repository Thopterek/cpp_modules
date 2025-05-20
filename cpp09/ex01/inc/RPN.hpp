#ifndef	RPN_HPP
#define	RPN_HPP

#include <iostream>
#include <regex>
#include <list>

class	RPN {
	private:
		std::list<int>	l_stack;
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		/*
			OCF above and below
			string to polish notation
		*/
		void	calculator(std::string &input);
};

#endif