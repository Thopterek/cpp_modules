/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:10:19 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/06 13:49:56 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

static void	subject_test() {
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

static void print_msg(std::string msg) {
	std::cout << std::string(msg.size(), '#') << std::endl;
	std::cout << msg << std::endl;
	std::cout << std::string(msg.size(), '#') << std::endl;
}

int	main(void) {
	print_msg("Subject tests");
	subject_test();
	print_msg("Now my own tests, with more functions");
	MutantStack<std::string>	str_stack;
	std::cout << "check if its empty, false is 0: " << str_stack.empty() << std::endl;
	str_stack.emplace(3, 'A');
	std::cout << "The top of the stack after emplace: " << str_stack.top() << std::endl;
	std::cout << "check if its empty, false is 0: " << str_stack.empty() << std::endl;
	str_stack.push("This is a string");
	str_stack.push("And here is another");
	std::cout << "the size of stack is: " << str_stack.size() << std::endl;
	MutantStack<std::string>	empty;
	str_stack.swap(empty);
	std::cout << "after using swap on empty stack: " <<  str_stack.size() << std::endl;
	std::cout << "and empty stack has now: " << empty.size() << std::endl;
	MutantStack<std::string>::iterator it = empty.begin();
	std::cout << "the begin is equal to: " << *it << std::endl;
	std::cout << "and going through the whole stack below:" << std::endl;
	while (it != empty.end()) {
		std::cout << *it << std::endl;
		++it;
	}
	const MutantStack<std::string>::iterator end = empty.begin();
	std::cout << "const begin is: " << *end << std::endl;
	return (EXIT_SUCCESS);
}