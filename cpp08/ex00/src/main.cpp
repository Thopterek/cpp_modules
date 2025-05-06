/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:42:54 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/05 10:59:52 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

static void print_msg(std::string msg) {
	std::cout << std::string(msg.size(), '#') << std::endl;
	std::cout << msg << std::endl;
	std::cout << std::string(msg.size(), '#') << std::endl;
}

int	main(void) {
	std::vector<int> v {9,0,4,1,8,3,4,3,9};
	print_msg("First time, trying to find 0 and then 2");
	try {
		int i = easyfind(v, 0);
		std::cout << "found in default container: " << i << std::endl; 
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		int i = easyfind(v, 2);
		std::cout << "found: " << i << std::endl; 
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	print_msg("Trying with other non-associative containers");
	std::list<int> l {123, 4, 1};
	std::forward_list<int> f {22, 2, 232, 5};
	std::deque<int> d {111, 1, 10, 6};
	try {
		int i = easyfind(l, 1);
		std::cout << "found in doubly-linked list: " << i << std::endl;
		i = easyfind(f, 2);
		std::cout << "found in singly-linked list: " << i << std::endl;
		i = easyfind(d, 5);
		std::cout << "found in double-ended queue: " << i << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	print_msg("And with an empty container");
	std::vector<int> empty;
	try {
		int i = easyfind(empty, 0);
		std::cout << "should not print: " << i << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}