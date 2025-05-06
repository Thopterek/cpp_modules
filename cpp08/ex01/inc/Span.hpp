#ifndef	SPAN_HPP
#define	SPAN_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <numeric>

class	Span {
	private:
		unsigned int	max;
		unsigned int	stored;
		std::deque<int> storage;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &other);
		Span	&operator=(const Span &other);
		/*
			OC form above and extra constructor
			below the helper member functions
		*/
		void	addNumber(int number);
		void	addRangeNumbers(int low, int high);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		/*
			extra exceptions
			if storage is empty
			or storage is full
			+ the range is wrong
		*/
		class	NoSpace : public std::exception {
			public:
				const char	*what() const throw();
		};
		class	NoSpan : public std::exception {
			public:	
				const char	*what() const throw();
		};
		class	WrongRange : public std::exception {
			public:
				const char	*what() const throw();
		};
};

#endif