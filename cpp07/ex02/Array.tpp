/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:53:42 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/02 10:29:49 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array()
:	array(nullptr), elements(0)
{}

template<typename T>
Array<T>::Array(unsigned int n) 
:	elements(n)
{
	if (n == 0)
		array = nullptr;
	else {
		array = static_cast<T*>(::operator new[](n * sizeof(T)));
		for (unsigned int i = 0; i < n; i++)
			new (&array[i]) T();
	}
}

template<typename T>
Array<T>::~Array() {
	if (array != nullptr) {
		for (unsigned int i = 0; i < elements; i++)
			array[i].~T();
		::operator delete[](array);
	}
}

template<typename T>
Array<T>::Array(const Array &other)
:	elements(other.elements)
{
	if (elements == 0)
		array = nullptr;
	else {
		array = static_cast<T*>(::operator new[](elements * sizeof(T)));
		for (unsigned int i = 0; i < elements; i++)
			new (&array[i]) T(other.array[i]);
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		for (unsigned int i = 0; i < elements; i++)
			array[i].~T();
		::operator delete[](array);
		elements = other.elements;
		array = static_cast<T*>(::operator new[](elements * sizeof(T)));
		for (unsigned int i = 0; i < elements; i++)
			new (&array[i]) T(other.array[i]);
	}
	return (*this);
}

template<typename T>
unsigned int	Array<T>::size() const {
	return (elements);
}

template<typename T>
T	&Array<T>::operator[](unsigned int index) {
	if (index >= elements)
		throw std::out_of_range("index out of bounds");
	return (array[index]);
}

template<typename T>
const T	&Array<T>::operator[](unsigned int index) const {
	if (index >= elements)
		throw std::out_of_range("index out of bounds");
	return (array[index]);
}