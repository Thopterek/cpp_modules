/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:46 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 11:34:43 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

static void	checkCinEof(void) {
	if (std::cin.eof()) {
		std::cin.clear();
		freopen("/dev/tty", "r", stdin);
	}
}

static void	prompt_msg(void) {
	std::string border(33, '#');
	std::cout << "\033[1m" << border << std::endl;
	std::cout << "#\tUsage of phone_book:\t#" << std::endl;
	std::cout << std::string(33, '#') << "\033[0m" << std::endl;
	std::cout << "ADD: saving the contact" << std::endl;
	std::cout << "SEARCH: display contacts" << std::endl;
	std::cout << "EXIT: quits the program" << std::endl;
}

static std::string get_input(std::string str) {
	std::string input;
	if (str != "")
		std::cout << str << std::flush;
	std::cout << "your input: " << std::flush;
	checkCinEof();
	std::getline(std::cin, input);
	return (input);
}

static void ignore_msg(std::string str) {
	std::string bold_c = "\033[33m\033[1m";
	std::cout << bold_c << "YOU GOT IGNORED" << "\033[0m" << std::endl;
	if (str != "")
		std:: cout << str << std::endl;
}

static void contact_fields(PhoneBook& phone_book)
{
	int	i = phone_book.get_saved_number();
	Contact* contacts = phone_book.get_contact_arr();
	phone_book.set_saved_number(i + 1);
	if (i >= phone_book.get_max_contact())
	{
		for (int m = 0; m < phone_book.get_max_contact() - 1; m++)
			contacts[m] = contacts[m + 1];
		i = phone_book.get_max_contact() - 1;
		contacts[i].set_value_of(Contact::FIRST, "");
		contacts[i].set_value_of(Contact::LAST, "");
		contacts[i].set_value_of(Contact::NICK, "");
		contacts[i].set_value_of(Contact::PHONE, "");
		contacts[i].set_value_of(Contact::SECRET, "");
	}
	while (contacts[i].get_value_of(Contact::FIRST) == "") {
		contacts[i].set_value_of(Contact::FIRST, get_input("saving first name, "));
		if (contacts[i].get_value_of(Contact::FIRST) == "")
			ignore_msg("fields can't be empty!");
	}
	while (contacts[i].get_value_of(Contact::LAST) == "") {
		contacts[i].set_value_of(Contact::LAST, get_input("now last name, "));
		if (contacts[i].get_value_of(Contact::LAST) == "")
			ignore_msg("as before, fields can't be empty!");
	}
	while (contacts[i].get_value_of(Contact::NICK) == "") {
		contacts[i].set_value_of(Contact::NICK, get_input("nickname please, "));
		if (contacts[i].get_value_of(Contact::NICK) == "")
			ignore_msg("hey... fields can't be empty!");
	}
	while (contacts[i].get_value_of(Contact::PHONE) == "") {
		contacts[i].set_value_of(Contact::PHONE, get_input("phon3 numb3r, "));
		if (contacts[i].get_value_of(Contact::PHONE) == "")
			ignore_msg("look, fields can't be empty!");
	}
	while (contacts[i].get_value_of(Contact::SECRET) == "") {
		contacts[i].set_value_of(Contact::SECRET, get_input("darkset secret... "));
		if (contacts[i].get_value_of(Contact::SECRET) == "")
			ignore_msg("why nothing? you need to fill it out!");
	}
}

static void proper_cout(std::string str) {
	std::string output = str.substr(0, 10);
	if (output.length() == 10)
		output.replace(9, 1, ".", 1);
	std::cout << std::setw(10);
	std::cout << output << "\033[1m|\033[0m" << std::flush;
}

static void display(PhoneBook& phone_book)
{
	Contact* contacts = phone_book.get_contact_arr();
	if (phone_book.get_saved_number() == 0) {
		ignore_msg("there are no contacts to be displayed");
		return;
	}
	int	max = phone_book.get_saved_number();
	if (max > phone_book.get_max_contact())
		max = phone_book.get_max_contact();
	std::cout << "\033[1m" << std::string(44, '#') << std::endl;
	std::cout << "\tThere are 44 # on top and bottom" << std::endl;
	std::cout << std::string(44, '#') << "\033[0m" << std::endl;
	for (int i = 0; i < max; i++) {
		std::cout << std::setw(10);
		std::cout << i << "\033[1m|\033[0m" << std::flush;
		proper_cout(contacts[i].get_value_of(Contact::FIRST));
		proper_cout(contacts[i].get_value_of(Contact::LAST));
		proper_cout(contacts[i].get_value_of(Contact::NICK));
		std::cout << std::endl;
	}
	bool flag = false;
	while (flag == false) {
		std::string input = get_input("write who you want to see, ");
		try {
			int index = std::stoi(input);
			if (0 > index || index > max - 1) {
				ignore_msg("outside of the scope (use index)");
			}
			else {
				flag = true;
				std::cout << "\033[1m" << std::string(44, '#') << std::endl;
				std::cout << "\tAll the saved informations" << std::endl;
				std::cout << std::string(44, '#') << "\033[0m" << std::endl;
				std::cout << "first name: " << contacts[index].get_value_of(Contact::FIRST) << std::endl;
				std::cout << "last name: " << contacts[index].get_value_of(Contact::LAST) << std::endl;
				std::cout << "nickname: " << contacts[index].get_value_of(Contact::NICK) << std::endl;
				std::cout << "phone number: " << contacts[index].get_value_of(Contact::PHONE) << std::endl;
				std::cout << "darkest secret: " << contacts[index].get_value_of(Contact::SECRET) << std::endl;
			}
		}
		catch (std::invalid_argument& e) {
			ignore_msg("this wasn't an integer, try again");
		}
		catch (std::out_of_range& e) {
			ignore_msg("please keep the program intact (range)");
		}

	}
}

int	main(void) {
	PhoneBook phone_book;
	while (true) {
		prompt_msg();
		std::string input = get_input("");
		if (input.compare("EXIT") == 0)
			break;
		else if (input == "ADD")
			contact_fields(phone_book);
		else if (input.compare("SEARCH") == 0)
			display(phone_book);
		else
			ignore_msg("");
	}
	return (0);
}
