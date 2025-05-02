#ifndef	WHATEVER_HPP
#define	WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T &first, T &second) {
	if (first != second) {
		auto tmp = first;
		first = second;
		second = tmp;
	}
}

template<typename T>
T	&min(T &first, T &second) {
	return ((first < second) ? first : second);
}

template<typename T>
T	&max(T &first, T &second) {
	return ((first > second) ? first : second);
}

#endif