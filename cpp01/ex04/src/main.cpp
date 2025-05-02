/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:09:36 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/08 12:24:41 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

static void	check_cin_eof(void) {
	if (std::cin.eof()) {
		std::cin.clear();
		freopen("/dev/tty", "r", stdin);
	}
}

/*
	it takes 3 parameters with ac & av
	or I make you fill it out more C++ way
*/
int	main(int ac, char **av) {
	std::string	file_name = "";
	std::string	tb_replaced;
	std::string	new_str;
	std::string	content;
	/*
		I could just output an error
		but that seems way more fun
	*/
	if (ac != 4) {
		std::cout << "wrong number of arguments, fill it out properly" << std::endl;
		while (file_name == "") {
			std::cout << "put a file to be read from: " << std::flush;
			check_cin_eof();
			getline(std::cin, file_name);
			/*
				might need to change to file_name.c_str()
				but if compiler extends it then I am fine
				as we are allowed to use C++11
			*/
			std::ifstream	file(file_name);
			if (file.good() == false) {
				std::cerr << "Error: '" << file_name << "' not found, try again" <<std::endl;
				file_name = "";
			}
			else
				content = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
		}
		std::cout << "now put a string to be replaced in that file: " << std::flush;
		check_cin_eof();
		getline(std::cin, tb_replaced);
		std::cout << "and the new string thats gonna take it place: " << std::flush;
		check_cin_eof();
		getline(std::cin, new_str);
	}
	else {
		file_name = av[1];
		std::ifstream	file(file_name);
		if (file.good() == false) {
			std::cerr << "Error: '" << file_name << "' not found, bye" << std::endl;
			return (EXIT_FAILURE);
		}
		content = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
		tb_replaced = av[2];
		new_str = av[3];
	}
	size_t	pos = 0;
	if (tb_replaced.empty() == true || content.empty() == true)
		std::cout << "hey, there are no changes to be done but here is the new file" << std::endl;
	else {
		while (content.find(tb_replaced, pos) != std::string::npos) {
			pos = content.find(tb_replaced, pos);
			content.erase(pos, tb_replaced.length());
			content.insert(pos, new_str);
			pos += new_str.length();
		}
	}
	std::ofstream	file(file_name + ".replace");
	file << content;
	return (EXIT_SUCCESS);
}