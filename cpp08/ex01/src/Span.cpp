/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:55:45 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/06 13:54:49 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span()
:	max(0), stored(0), storage()
{}

Span::Span(unsigned int N)
:	max(N), stored(0), storage()
{}

Span::~Span() {}

Span::Span(const Span &other)
:	max(other.max), stored(other.stored), storage(other.storage)
{}

Span	&Span::operator=(const Span &other) {
	if (this != &other) {
		Span	tmp(other);
		std::swap(max, tmp.max);
		std::swap(stored, tmp.stored);
		std::swap(storage, tmp.storage);	
	}
	return (*this);
}

void	Span::addNumber(int number) {
	if (max == stored) {
		throw NoSpace();
		return ;
	}
	storage.push_front(number);
	stored += 1;
}

void	Span::addRangeNumbers(int low, int high) {
	if (low > high)
		throw WrongRange();
	if (max == stored || high - low > static_cast<int>(max - stored))
		throw NoSpace();
	std::deque<int> range(high - low);
	std::iota(range.begin(), range.end(), low);
	storage.insert(storage.begin(), range.begin(), range.end());
	stored += range.size();
}

unsigned int	Span::shortestSpan() const {
	if (stored <= 1)
		throw NoSpan();
	std::deque<int> sorted(storage.begin(), storage.end());
	std::sort(sorted.begin(), sorted.end());
	std::deque<unsigned int>	diff(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), diff.begin());
	auto ret = std::min_element(begin(diff), end(diff));
	return (*ret);
}

unsigned int	Span::longestSpan() const {
	if (stored <= 1)
		throw NoSpan();
	auto [min, high] = std::minmax_element(begin(storage), end(storage));
	return (*high - *min);
}

const char	*Span::NoSpace::what() const throw() {
	return ("There is no space left to add more numbers");
}

const char	*Span::NoSpan::what() const throw() {
	return ("No Span is possible for calculation");
}

const char	*Span::WrongRange::what() const throw() {
	return ("Range should start from smaller number and end with higher");
}