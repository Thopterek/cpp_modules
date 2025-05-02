/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:59:23 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/14 11:22:17 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

/*
	first part is copy paste with added deletes
	after it there are my own tests being made
*/
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	/*
		from this point are starting my tests
		but first cleanining up the new things
	*/
	delete	meta;
	delete	j;
	delete	i;
	std::cout << std::string(28, '#') << std::endl;
	std::cout << " Clean up and my own tests" << std::endl;
	std::cout << std::string(28, '#') << std::endl;
	Dog	doggy;
	Cat	kitty;
	doggy.makeSound();
	kitty.makeSound();
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << wrong_meta->getType() << " empty type of WrongAnimal" << std::endl;
	std::cout << wrong_cat->getType() << " the type of WrongCat" << std::endl;
	wrong_meta->makeSound();
	wrong_cat->makeSound();
	delete	wrong_meta;
	delete	wrong_cat;
	std::cout << std::string(46, '#') << std::endl;
	std::cout << " Deconstructors after going outside of scope" << std::endl;
	std::cout << std::string(46, '#') << std::endl;
	return (0);
}