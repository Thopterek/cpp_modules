#ifndef	MUTANTSTACK_HPP
#define	MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <utility>

template<typename T>
class	MutantStack : public std::stack<T> {
	public:
		/*
			mandatory
			 OC form
		*/
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack	&operator=(const MutantStack &other);
		/*
			per the C++17 options all the member functions
			not needed as class is inherting from std::stack
			made for prior version when operating on member
			std::stack<T> but now just a wrappers
		*/
		const T	&top() const;
		bool	empty() const;
		size_t	size() const;
		void	push(T value);
		template<typename... Args>
		void	emplace(Args&&... args);
		void	pop();
		void	swap(MutantStack &other);
		/*
			now the extra addition
			which are the iterators
			exposing the underlaying
			container of std::stack
			- begin: first element
			- end: one behind last
			stack doesn't have reverse
		*/
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
		/*
			below the const version
			with new defintion for it
		*/
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"

#endif