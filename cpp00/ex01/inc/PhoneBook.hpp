#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contact_arr[8];
		int		max_contacts;
		int		saved_number;
	public:
		/*
			Orthodox Canonical Form
			- default constructor
			- copy constructor
			- copy assingment operator
			- destructor
		*/
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		PhoneBook& operator=(const PhoneBook& other);
		~PhoneBook();
		/*
				Helper getters
			accessing the private
		*/
		Contact* get_contact_arr();
		int get_max_contact() const;
		int	get_saved_number() const;
		/*
			setter to update saved numbers
		*/
		void set_saved_number(int i);
};

#endif