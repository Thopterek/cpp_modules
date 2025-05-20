#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

#include <iostream>
#include <regex>
#include <fstream>
#include <map>
#include <algorithm>

class	BitcoinExchange {
	private:
		std::map<std::string, float>	database;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		/*
			above the OCF and below:
			- saving the data to compare
			- returning value close to date
			- checking the data from user
		*/
		bool	LoadDatabase(std::ifstream &file_data);
		float	FindDate(std::string date);
		void	CheckUserData(std::ifstream &file_user);
};

#endif