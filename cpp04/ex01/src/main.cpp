/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:59:23 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/16 11:29:47 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

/*
	checking for the leaks
void	leaks() {
	system("leaks i_dont_want");
}
atexit(leaks);
*/
int main() {
	std::cout << std::string(30, '#') << std::endl;
	std::cout << "Creating the array of Animals" << std::endl;
	const	Animal*	array[6];
	std::cout << std::string(30, '#') << std::endl;
	std::cout << "Filling half of it with dogs" << std::endl;
	std::cout << std::string(30, '#') << std::endl;
	for (int i = 0; i < 3; i++)
		array[i] = new Dog();
	std::cout << std::string(30, '#') << std::endl;
	std::cout << "Filling the other half with cats" << std::endl;
	std::cout << std::string(30, '#') << std::endl;
	for (int i = 3; i < 6; i++)
		array[i] = new Cat();
	std::cout << std::string(30, '#') << std::endl;
	std::cout << "deleting every animal in the array" << std::endl;
	std::cout << std::string(30, '#') << std::endl;
	for (int i = 0; i < 6; i++)
		delete array[i];
	std::cout << std::string(30, '#') << std::endl;
	std::cout << "checking for the deep copies" << std::endl;
	std::cout << std::string(30, '#') << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}
	return (0);
}