#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <regex>
#include <string>
#include <chrono>
#include <utility>
#include <cctype>
#include <complex>

class	PmergeMe {
	private:
		std::vector<int> vec;
		std::deque<int> que;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		PmergeMe(unsigned int size);
		/*
			above the OCF with extra constructor
			to reserve the place for the input
			below are the main sorting functions
		*/
		void	sort_vector(size_t next_a_one, size_t group);
		void	sort_deque(size_t next_a_one, size_t group);
		/*
			but before using them there are data managers
			to insert the checked input from the user
		*/
		template<typename T>
		void	insert_data_vector(T &other);
		template<typename T>
		void	insert_data_deque(T &other);
		/*
			helper functions to display containers
			used before actual sorting and after
		*/
		void	display_vector(std::string msg) const;
		void	display_deque(std::string msg) const;
};

#include "PmergeMe.tpp"

#endif