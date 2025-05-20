/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:22:31 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/16 15:49:19 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() : vec(), que() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), que(other.que) {}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		PmergeMe	tmp(other);
		std::swap(vec, tmp.vec);
		std::swap(que, tmp.que);
	}
	return (*this);
}

PmergeMe::PmergeMe(unsigned int size) : vec(), que() {
	vec.reserve(size);
}

/*
	first part of the algorithm is about working on pairs
	then pairs of pairs and so on to swap them in place
	and here are some test cases:
	0 8 4 3 5 1 6 7 2
	11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
	./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
*/
void	PmergeMe::sort_vector(size_t next_a_one, size_t group) {
	size_t	power = 1 << group;
	size_t	move = 1 << (group + 1);
	if (move > vec.size())
		return ;
	size_t	save = 0;
	size_t	ranges = next_a_one;
	for (size_t i = next_a_one; i < vec.size(); i += move) {
		auto	a = vec.begin() + i;
		auto	b = a - power;
		auto	start = a - ranges;
		auto	insert = b + 1;
		save++;
		if (save == 2)
			next_a_one = i;
		if (*b > *a)
			std::swap_ranges(start, start + power, insert);
	}
	sort_vector(next_a_one, group + 1);
	/*
		after ending the recursion going down we move the values
		the b1 and all the a1 are going to the main chain
		all the b n are going to go inside the pending
	*/
	std::vector<int>	main_c;
	std::vector<int>	pend;
	auto	start = vec.begin();
	std::move(start, start + move, std::back_inserter(main_c));
	for (size_t i = move; i < vec.size(); i += power) {
		start = vec.begin() + i;
		if (start + power > vec.end()) {
			break ;
		}
		if (i % move != 0)
			std::move(start, start + power, std::back_inserter(main_c));
		else
			std::move(start, start + power, std::back_inserter(pend));
	}
	/*
		now inserting the correct pairs from the pending
		inside the main chain using Jacobs Thal numbers
		b count gives the number of bn groups in pend
		if we can't use the Jacob Number we go for normal
	*/
	size_t	b_count = pend.size();
	size_t	total_moves = b_count / power;
	size_t	jacob_index = 3;
	size_t	jacob_number = (std::pow(2, jacob_index) - std::pow((-1), jacob_index)) / 3;
	size_t	jacob_position = ((jacob_number - 1) * power) - 1;
	size_t	moved = 0;
	if (jacob_position < b_count) {
		auto	b_to_compare = pend.begin() + jacob_position;
		auto	b_group = b_to_compare - (power - 1);
		auto	border = pend.begin();
		auto	next_border = b_to_compare + 1;
		while (total_moves > moved) {
			auto	against = main_c.begin() + power - 1;
			auto	place_b = main_c.begin();
			while (*b_to_compare >= *against) {
				if (against == main_c.end() - 1) {
					place_b += power;
					break ;
				}
				against += power;
				place_b += power;
			}
			main_c.insert(place_b, b_group, b_group + power);
			moved++;
			if (b_group > border) {
				b_to_compare -= power;
				b_group = b_to_compare - (power - 1);
			} else {
				border = next_border;
				jacob_index++;
				jacob_number = (std::pow(2, jacob_index) - std::pow((-1), jacob_index)) / 3;
				jacob_position = ((jacob_number - 1) * power) - 1;
				if (jacob_position >= b_count) {
					b_to_compare = pend.end() - 1;
					b_group = b_to_compare - (power - 1);
				} else {
					b_to_compare = pend.begin() + jacob_position;
					b_group = b_to_compare - (power - 1);
				}
				next_border = b_to_compare + 1;
			}
		}
	} else if (pend.empty() == false) {
		auto	bn = pend.begin() + power - 1;
		auto	b_or_an = main_c.begin() + power - 1;
		auto	placement = main_c.begin();
		while (*bn >= *b_or_an) {
			if (b_or_an == main_c.end() - 1) {
				placement += power;
				break ;
			}
			b_or_an += power;
			placement += power;
		}
		main_c.insert(placement, pend.begin(), pend.end());
	}
	/*
		putting the correct values inside the starting vec
		by replacing the values inside it from the ones in main
		therefore changing the startin sequence for next call
	*/
	std::swap_ranges(main_c.begin(), main_c.end(), vec.begin());
}

/*
	same algorithm as the one above but with some extra comments
	mostly about the things that were not explained before plus
	trying to use std::next and previous to try extra things
*/
void	PmergeMe::sort_deque(size_t next_a_one, size_t group) {
	size_t	power = 1 << group;
	size_t	move = 1 << (group + 1);
	if (move > que.size())
		return ;
	size_t	save = 0;
	size_t	ranges = next_a_one;
	for (size_t i = next_a_one; i < que.size(); i += move) {
		auto	a = std::next(que.begin(), i);
		auto	b = std::prev(a, power);
		auto	start = std::prev(a, ranges);
		auto	insert = std::next(b, 1);
		save++;
		if (save == 2)
			next_a_one = i;
		if (*b > *a)
			std::swap_ranges(start, std::next(start, power), insert);
	}
	sort_deque(next_a_one, group + 1);
	std::deque<int>	main_c;
	std::deque<int>	pend;
	auto	start = que.begin();
	std::move(start, std::next(start, move), std::back_inserter(main_c));
	for (size_t i = move; i < que.size(); i += power) {
		start = std::next(que.begin(), i);
		if (i + power > que.size()) {
			break ;
		}
		if (i % move != 0)
			std::move(start, std::next(start, power), std::back_inserter(main_c));
		else
			std::move(start, std::next(start, power), std::back_inserter(pend));
	}
	size_t	b_count = pend.size();
	size_t	total_moves = b_count / power;
	size_t	jacob_index = 3;
	size_t	jacob_number = (std::pow(2, jacob_index) - std::pow((-1), jacob_index)) / 3;
	size_t	jacob_position = ((jacob_number - 1) * power) - 1;
	size_t	moved = 0;
	if (jacob_position < b_count) {
		auto	b_to_compare = std::next(pend.begin(), jacob_position);
		size_t	diff = power - 1;
		auto	b_group = std::prev(b_to_compare, diff);
		auto	border = pend.begin();
		auto	next_border = std::next(b_to_compare, 1);
		/*
			total moves is amount of groups to be inserted
			its the size of pending divided by numbers in group
		*/
		while (total_moves > moved) {
			auto	against = std::next(main_c.begin(), diff);
			auto	place_b = main_c.begin();
			/*
				>= is added if there would be duplicates
				as not to compare extra set/s of numbers
			*/
			while (*b_to_compare >= *against) {
				/*
					extra check if the b(n) to compare
					is bigger than everything in main
				*/
				if (against == std::prev(main_c.end(), 1)) {
					place_b = std::next(place_b, power);
					break ;
				}
				against = std::next(against, power);
				place_b = std::next(place_b, power);
			}
			main_c.insert(place_b, b_group, std::next(b_group, power));
			moved++;
			/*
				first if statement is going down from jacob number n
				per n = 3, b(n) then (b n - 1) till we hit the border
				then we go to the next jacob number n = 5 so b(n) b(n - 1)
				one more time and it jumps to n = 11 so b(n) till b(6)
			*/
			if (b_group > border) {
				b_to_compare = std::prev(b_to_compare, power);
				b_group = std::prev(b_to_compare, diff);
			} else {
				border = next_border;
				jacob_index++;
				jacob_number = (std::pow(2, jacob_index) - std::pow((-1), jacob_index)) / 3;
				jacob_position = ((jacob_number - 1) * power) - 1;
				if (jacob_position >= b_count) {
					b_to_compare = std::prev(pend.end(), 1);
					b_group = std::prev(b_to_compare, diff);
				} else {
					b_to_compare = std::next(pend.begin(), jacob_position);
					b_group = std::prev(b_to_compare, diff);
				}
				next_border = std::next(b_to_compare, 1);
			}
		}
	} else if (pend.empty() == false) {
		/*
			happens if there is only one group b(2) in pend
			then we just need to add the whole pending sequence
		*/
		size_t	diff = power - 1;
		auto	bn = std::next(pend.begin(), diff);
		auto	b_or_an = std::next(main_c.begin(), diff);
		auto	placement = main_c.begin();
		while (*bn >= *b_or_an) {
			if (b_or_an == std::prev(main_c.end(), 1)) {
				placement = std::next(placement, power);
				break ;
			}
			b_or_an = std::next(b_or_an, power);
			placement = std::next(placement, power);
		}
		main_c.insert(placement, pend.begin(), pend.end());
	}
	std::swap_ranges(main_c.begin(), main_c.end(), que.begin());
}

void	PmergeMe::display_vector(std::string msg) const {
	std::cout << msg << std::flush;
	auto	it = vec.begin();
	auto	end = vec.end();
	while (it != end) {
		std::cout << *it << " " << std::flush;
		++it;
	}
	std::cout << std::endl;
}

void	PmergeMe::display_deque(std::string msg) const {
	std::cout << msg << std::flush;
	auto	it = que.begin();
	auto	end = que.end();
	while (it != end) {
		std::cout << *it << " " << std::flush;
		++it;
	}
	std::cout << std::endl;	
}
