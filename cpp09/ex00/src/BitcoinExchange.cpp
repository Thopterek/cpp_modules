/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:39:58 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/05/19 15:15:12 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : database() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
: database(other.database)
{}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		BitcoinExchange	tmp(other);
		std::swap(database, tmp.database);
	}
	return (*this);
}

float	BitcoinExchange::FindDate(std::string date) {
	float	found = -1;
	try {
		found = database.at(date);
	} catch (std::out_of_range &e) {
		auto	it = database.lower_bound(date);
		if (it != database.begin())
			--it;
		found = it->second;
	}
	return (found);
}

void	BitcoinExchange::CheckUserData(std::ifstream &file_user) {
	std::regex	line_pattern(R"(\d{4}-\d{2}-\d{2} \| \d+.*\d*)");
	std::regex	date_pattern(R"(\d{4}-[0-1]{1}[0-9]{1}-[0-3]{1}[0-9]{1})");
	std::regex	value_pattern(R"(\d+.*\d*)");
	std::string	line;
	while (std::getline(file_user, line)){
		std::string date = line.substr(0, line.find('|') - 1);
		std::string	value = line.substr(line.find('|') + 2, line.size());
		if (std::regex_match(value, value_pattern) == false)
			std::cout << "Error: value is not a positive number" << std::endl;
		else if (std::regex_match(date, date_pattern) == false)
			std::cout << "Error: date in wrong format" << std::endl;
		else if (std::regex_match(line, line_pattern) == false)
			std::cout << "Error: bad input => " << line << std::endl;
		else if (std::stoi(date.substr(0, line.find('-'))) < 2009)
			std::cout << "Error: year before bitcoin launch" << std::endl;
		else if (std::stoi(date.substr(line.find('-') + 1, line.find('-') + 3)) > 12 ||
			std::stoi(date.substr(line.find('-') + 1, line.find('-') + 3)) < 1)
			std::cout << "Error: not a real month" << std::endl;
		else if (std::stoi(date.substr(date.size() - 2, date.size())) > 31 ||
			std::stoi(date.substr(date.size() - 2, date.size())) < 1)
			std::cout << "Error: not a real day" << std::endl;
		else {
			try {
				float	numeric = std::stof(value);
				if (numeric > 1000)
					std::cout << "Error: number it too large" << std::endl;
				else {
					float	total = numeric * FindDate(date);
					std::cout << date << " => " << numeric << " = " << total << std::endl;
				}
			} catch (std::out_of_range &e) {
				std::cout << e.what() << std::endl;
			}
		}
	}
}

bool	BitcoinExchange::LoadDatabase(std::ifstream &file_data) {
	std::regex	csv_pattern(R"(\d{4}-\d{2}-\d{2},\d+.*\d*)");
	std::string	line;
	size_t	exact_line = 2;
	while (std::getline(file_data, line)) {
		if (std::regex_match(line, csv_pattern) == false) {
			std::cerr << "Error: data.csv at line " << exact_line << " corrupted" << std::endl;
			return (false);
		}
		std::string	to_float = line.substr(line.find(',') + 1, line.size());
		try {
			auto	pair = std::make_pair(line.substr(0, line.find(',')), std::stof(to_float));
			database.insert(pair);
		} catch (std::exception &e) {
			std::cerr << "Error: data.csv, ignoring line -> " << line << std::endl;
		}
		exact_line++;
	}
	return (true);
}