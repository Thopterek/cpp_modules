/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:53 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/29 15:13:02 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base::~Base()
{}

Base	*generate(void) {
	std::srand(std::time(0));
	int	number = std::rand() % 3 + 1;
	switch (number) {
		case (1):
			std::cout << "generated randomly: A" << std::endl;
			return (new A());
		case (2):
			std::cout << "generated randomly: B" << std::endl;
			return (new B());
		default:
			std::cout << "generated randomly: C" << std::endl;
			return (new C());
	}
}

void	identify(Base *p) {
	std::cout << "Type verification with pointer to Base: " << std::flush;
	if (p == nullptr) {
		std::cout << nullptr << std::endl;
		return ;
	}	
	A	*a = dynamic_cast<A*>(p);
	if (a != nullptr) {
		std::cout << "type found A" << std::endl;
		return ;
	}
	B	*b = dynamic_cast<B*>(p);
	if (b != nullptr) {
		std::cout << "type found B" << std::endl;
		return ;
	}
	C	*c = dynamic_cast<C*>(p);
	if (c != nullptr) {
		std::cout << "type found C" << std::endl;
		return ;
	}
	std::cout << "type not derived class" << std::endl;
}

void	identify(Base &p) {
	std::cout << "Type verification with reference to Base: " << std::flush;
	Base	*ptr = &p;
	if (ptr == nullptr) {
		std::cout << nullptr << std::endl;
		return ;
	}
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "found A" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "found B" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "found C" << std::endl;
		return ;
	} catch (std::exception &e) {}
	std::cout << "type not in derived class" << std::endl;
}