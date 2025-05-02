/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:31:36 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/16 16:00:38 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

// void	leaks(void) {
// 	system("leaks recap");
// }
/*
	Copy paste part of main
	my starts after delete src
*/
int main() {
	// atexit(leaks);
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "base test from the subject" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << std::string(33, '#') << std::endl;
	std::cout << "some actual tests being done" << std::endl;
	std::cout << std::string(33, '#') << std::endl;
	IMateriaSource	*i_mater = new MateriaSource();
	i_mater->learnMateria(new Ice());
	i_mater->learnMateria(new Ice());
	i_mater->learnMateria(new Ice());
	i_mater->learnMateria(new Ice());
	i_mater->learnMateria(new Ice());
	std::cout << "Checked if limits for learnMateria works" << std::endl;
	std::cout << "Now trying to create a Materia cure but learned only ICE" << std::endl;
	AMateria	*to_use = i_mater->createMateria("cure");
	std::cout << "This time trying to learn the Ice" << std::endl;
	to_use = i_mater->createMateria("ice");
	std::cout << "and testing so it works by creating a two characters and using it" << std::endl;
	ICharacter	*jon = new Character("JOHN");
	ICharacter	*target = new Character("Enemy");
	jon->equip(to_use);
	jon->use(0, *target);
	std::cout << "then trying to use the thing from second index" << std::endl;
	jon->use(1, *target);
	std::cout << "nothing happend as it should now I will try to equip over the limit" << std::endl;
	to_use = i_mater->createMateria("ice");
	jon->equip(to_use);
	to_use = i_mater->createMateria("ice");
	jon->equip(to_use);
	to_use = i_mater->createMateria("ice");
	jon->equip(to_use);
	to_use = i_mater->createMateria("ice");
	jon->equip(to_use);
	std::cout << "creating the copy of jon and using what it inherited" << std::endl;
	ICharacter *jon_copy = new Character(*jon);
	jon_copy->use(0, *jon);
	std::cout << "after this unequiping the thing to test if clean floors works" << std::endl;
	jon->unequip(0);
	jon->unequip(0);
	jon->unequip(0);
	jon->unequip(0);
	delete target;
	delete jon;
	delete jon_copy;
	delete i_mater;
	Floor::cleanFloor();
	return (0);
}