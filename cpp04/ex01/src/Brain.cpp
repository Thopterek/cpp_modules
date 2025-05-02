/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:57:05 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/14 13:44:44 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		setIdea(i, "");
	std::cout << "BRAIN got constructed by default" << std::endl;
}

Brain::~Brain() {
	std::cout << "BRAIN is no more, destructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++)
		ideas[i] = other.getIdea(i);
	std::cout << "BRAIN got copied idea by idea" << std::endl;
}

Brain	&Brain::operator=(const Brain &other) {
	Brain tmp(other);
	for (int i = 0; i < 100; i++)
		std::swap(ideas[i], tmp.ideas[i]);
	std::cout << "BRAIN copy assingment operator used" << std::endl;
	return (*this);
}

void	Brain::setIdea(int which, std::string idea) {
	ideas[which] = idea;
}

std::string	Brain::getIdea(int which) const {
	return (ideas[which]);
}