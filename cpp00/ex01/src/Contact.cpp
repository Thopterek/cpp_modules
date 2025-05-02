/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:41 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/07 11:45:42 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact()
:	first_name(""),
	last_name(""),
	nickname(""),
	phone_number(""),
	darkest_secret("")
{}

Contact::Contact(const Contact& other)
:	first_name(other.first_name),
	last_name(other.last_name),
	nickname(other.nickname),
	phone_number(other.phone_number),
	darkest_secret(other.darkest_secret)
{}

Contact& Contact::operator=(const Contact& other) {
	if (this == &other)
		return (*this);
	first_name = other.first_name;
	last_name = other.last_name;
	nickname = other.nickname;
	phone_number = other.phone_number;
	darkest_secret = other.darkest_secret;
	return (*this);
}

Contact::~Contact() {
	/*
			Nothings to handle
		std::string manages itself
	*/
}

std::string Contact::get_value_of(flag flag) {
	switch (flag) {
		case FIRST: return (first_name);
		case LAST: return (last_name);
		case NICK: return (nickname);
		case PHONE: return (phone_number);
		case SECRET: return (darkest_secret);
		default: return ("Flag used wrongly");
	}
}

Contact& Contact::set_value_of(flag flag, std::string str) {
	switch (flag) {
		case FIRST: first_name = str; break;
		case LAST: last_name = str; break;
		case NICK: nickname = str; break;
		case PHONE: phone_number = str; break;
		case SECRET: darkest_secret = str; break;
		default: throw std::invalid_argument("Error: invalid flag");
	}
	return (*this);
}