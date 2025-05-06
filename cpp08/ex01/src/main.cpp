/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:55:43 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/05 16:04:21 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int	main(void) {
	Span	sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	/*
		testing the exceptions
	*/
	try {
		sp.addNumber(10);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp.addRangeNumbers(10, 5);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span	tmp = Span(1);
		tmp.addNumber(2);
		std::cout << tmp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	/*
		test from the subject above
		below mine own on bigger range
		filling up: 5k, 3k, 2k, 10k
	*/
	Span	big = Span(20000);
	big.addRangeNumbers(0, 5000);
	big.addRangeNumbers(10000, 13000);
	big.addRangeNumbers(-3000, -1000);
	big.addRangeNumbers(-5000, 5000);
	std::cout << "shortest: " << big.shortestSpan() << std::endl;
	std::cout << "longest: " << big.longestSpan() << std::endl;
	std::cout << "And now to see some big differences" << std::endl;
	Span	huge = Span(3);
	huge.addNumber(-2000000);
	huge.addNumber(0);
	huge.addNumber(147483647);
	std::cout << "shortest: " << huge.shortestSpan() << std::endl;
	std::cout << "longest: " << huge.longestSpan() << std::endl;
	return (EXIT_SUCCESS);
}