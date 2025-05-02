/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:52 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/07 11:45:53 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
:	max_contacts(8),
	saved_number(0)
{}

PhoneBook::PhoneBook(const PhoneBook &other)
:	max_contacts(other.max_contacts) {
	for (int i = 0; i < max_contacts; i++)
		contact_arr[i] = other.contact_arr[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
	if (this == &other)
		return (*this);
	max_contacts = other.max_contacts;
	for (int i = 0; i < max_contacts; i++)
		contact_arr[i] = other.contact_arr[i];
	return (*this);
}

PhoneBook::~PhoneBook() 
{
	/*
			Nothing to handle
		stack array handles itself
	*/
}

Contact* PhoneBook::get_contact_arr() {
	return (contact_arr);
}

int PhoneBook::get_max_contact() const {
	return (max_contacts);
}

int PhoneBook::get_saved_number() const {
	return (saved_number);
}

void PhoneBook::set_saved_number(int i) {
	saved_number = i;
}
