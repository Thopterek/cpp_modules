#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		/*
			Orthodox Canonical Form
			- default constructor
			- copy constructor
			- copy assingment operator
			- destructor
		*/
		Contact();
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
		~Contact();
		/*
			Enums to get the proper values:
			had fields for every private
		*/
		enum flag {
			FIRST,
			LAST,
			NICK,
			PHONE,
			SECRET
		};
		/*
			Get the value of strings
			compares the flag we set
			same for the set option
		*/
		std::string get_value_of(flag flag);
		Contact& set_value_of(flag flag, std::string str);
};

#endif