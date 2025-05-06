/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:10:24 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/06 13:43:04 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
:	std::stack<T>()
{}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
:	std::stack<T>(other)
{}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &other) {
	if (this != &other)
		std::stack<T>::operator=(other);	
	return (*this);
}

template<typename T>
const T	&MutantStack<T>::top() const {
	return (std::stack<T>::top());
}

template<typename T>
bool	MutantStack<T>::empty() const {
	return (std::stack<T>::empty());
}

template<typename T>
size_t	MutantStack<T>::size() const {
	return (std::stack<T>::size());
}

template<typename T>
void	MutantStack<T>::push(T value) {
	std::stack<T>::push(value);
}

template<typename T>
template<typename... Args>
void	MutantStack<T>::emplace(Args&&... args) {
	std::stack<T>::emplace(std::forward<Args>(args)...);
}

template<typename T>
void	MutantStack<T>::pop() {
	std::stack<T>::pop();
}

template<typename T>
void	MutantStack<T>::swap(MutantStack &other) {
	if (this != &other) {
		std::stack<T>::swap(other);
	}
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const {
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const {
	return (this->c.end());
}
