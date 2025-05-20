/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:28:00 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/20 17:51:23 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() : l_stack() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : l_stack(other.l_stack) {}

RPN	&RPN::operator=(const RPN &other) {
	if (this != &other) {
		RPN	tmp(other);
		std::swap(l_stack, tmp.l_stack);
	}
	return (*this);
}

void	RPN::calculator(std::string &input) {
	auto	it = input.begin();
	while (it != input.end())
	{
		try {
			int	number = std::stoi(std::string(1, *it));
			l_stack.push_front(number);
		} catch (std::invalid_argument &e) {
			int result = 0;
			int check = 0;
			if (*it == '*') {
				auto	num = std::next(l_stack.begin(), 1);
				result = *num * l_stack.front();
				check++;
			} else if (*it == '/') {
				if (l_stack.front() == 0) {
					std::cerr << "Error: no division by zero allowed" << std::endl;
					return ;
				}
				auto	num = std::next(l_stack.begin(), 1);
				result = *num / l_stack.front();
				check++;
			} else if (*it == '+') {
				auto	num = std::next(l_stack.begin(), 1);
				result = *num + l_stack.front();
				check++;
			} else if (*it == '-') {
				auto	num = std::next(l_stack.begin(), 1);
				result = *num - l_stack.front();
				check++;
			}
			if (check != 0) {
				if (l_stack.size() < 2) {
					std::cerr << "Error: invalid RPN expression" << std::endl;
					return ;
				}
				l_stack.pop_front();
				l_stack.pop_front();
				l_stack.push_front(result);
				check = 0;
			}
		}
		++it;
	}
	if (l_stack.size() != 1)
		std::cerr << "Error: unbalanced expression (not enough tokens or numbers)" << std::endl;
	else
		std::cout << l_stack.front() << std::endl;
}