#ifndef	ITER_HPP
#define	ITER_HPP

#include <iostream>

template<typename T, typename F>
void	iter(T *address, int size, F function) {
	if (address == nullptr)
		return;
	for (int i = 0; i < size; i++)
		function(address[i]);
}

#endif