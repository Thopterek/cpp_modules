#ifndef	EASYFIND_HPP
#define	EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>
#include <list>
#include <deque>
#include <forward_list>

template<typename T>
int	easyfind(T container, int tb_found);

class	NotFound : public std::exception {
	public:
		const char *what() const throw();
};

#include "easyfind.tpp"

#endif