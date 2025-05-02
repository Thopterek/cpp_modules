#ifndef	ARRAY_HPP
#define	ARRAY_HPP

#include <iostream>
#include <exception>

/*
	prototypes per subject
	need to remeber to use new[]
	as required per subject
	in the actual implementation
	same for accessing elements
	with the subscript operator []
*/
template<typename T>
class	Array {
	private:
		T	*array;
		unsigned int	elements;
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &other);
		Array	&operator=(const Array &other);
		unsigned int	size() const;
		/*
			operator written in two versions
			const and non const version
		*/
		T	&operator[](unsigned int index);
		const T	&operator[](unsigned int index) const;
};

/*
	.tpp used for implemnting
	the templates rather than
	keeping it inside .hpp file
*/
#include "Array.tpp"

#endif