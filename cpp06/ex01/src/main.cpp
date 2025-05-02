/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:31:42 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/29 12:11:51 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int	main(void) {
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "first tests creating data" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	Data	first;
	first.name = "first_data";
	first.used = false;
	std::cout << "Data name: " << first.name << std::endl;
	std::cout << "Boolean for usage: " << first.used << std::endl;
	std::cout << "Address: " << std::addressof(first) << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "trying to create a pointer" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	Data	*second = new Data;
	second->name = "second_data";
	second->used = true;
	std::cout << "Data name: " << second->name << std::endl;
	std::cout << "Boolean for usage: " << second->used << std::endl;
	std::cout << "Adress: " << std::addressof(second) << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "testing per subject by steps:" << std::endl;
	std::cout << "1: using serialize on address" << std::endl;
	std::cout << "2: pass it to return of deser." << std::endl;
	std::cout << "3: comparing orginal pointer" << std::endl;
	std::cout << " making for stack and heap" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	Data	*third = Serializer::deserialize(Serializer::serialize(second));
	std::cout << "Data name: " << third->name << std::endl;
	std::cout << "Boolean for usage: " << third->used << std::endl;
	std::cout << "Adress: " << std::addressof(third) << std::endl;
	std::cout << "and now for the stack allocated one:" << std::endl;
	third = Serializer::deserialize(Serializer::serialize(&first));
	std::cout << "Data name: " << third->name << std::endl;
	std::cout << "Boolean for usage: " << third->used << std::endl;
	std::cout << "Adress: " << std::addressof(third) << std::endl;
	delete second;
	return (EXIT_SUCCESS);
}