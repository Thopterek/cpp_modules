/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:14 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/04/07 11:45:15 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Account.hpp"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

/*
	breaking the rule of the rest:
	starting with static at the beginning
	first the variables and then time
	<ctime> C thing used only for the time
	<sstream> is for the ostringstream
	<iomanip> is for the fill function
*/
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void) {
	std::time_t			current = std::time(0);
	std::tm				*convert = std::localtime(&current);
	std::ostringstream	format;
	format << "[";
	format << (1900 + convert->tm_year);
	format << std::setw(2) << std::setfill('0') << (convert->tm_mon + 1);
	format << std::setw(2) << std::setfill('0') << convert->tm_mday;
	format << "_";
	format << std::setw(2) << std::setfill('0') << convert->tm_hour;
	format << std::setw(2) << std::setfill('0') << convert->tm_min;
	format << std::setw(2) << std::setfill('0') << convert->tm_sec;
	format << "]";
	std::cout << format.str() << std::flush;
}

/*
	Everything is written in order from Account.hpp
	so first are for getters and displayAccountsInfos
*/
int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void) {
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << std::flush;
	std::cout << ";total:" << getTotalAmount() << std::flush;
	std::cout << ";deposits:" << getNbDeposits() << std::flush;
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

/*
	non standard constructor (because takes arguments)
	and very similiar destructor, both to be seen
	at the top and at the end of the file
*/
Account::Account(int initial_deposit) 
:	_accountIndex(getNbAccounts()),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << std::flush;
	std::cout << ";amount:" << _amount << std::flush;
	std::cout << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << std::flush;
	std::cout << ";amount:" << _amount << std::flush;
	std::cout << ";closed" << std::endl;
}

/*
	Functions to update the Account: Deposit / Withdrawal,
	another getter but this time for the amount in account,
	and lastly the display Status that is the most used
*/
void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << std::flush;
	std::cout << ";p_amount:" << _amount << std::flush;
	std::cout << ";deposit:" << deposit << std::flush;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << std::flush;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << std::flush;
	std::cout << ";p_amount:" << _amount << std::flush;
	if (withdrawal <= 0) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else if (_amount < withdrawal) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal << std::flush;
		std::cout << ";amount:" << _amount << std::flush;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
}

int	Account::checkAmount(void) const {
	return (_amount);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << std::flush;
	std::cout << ";amount:" << _amount << std::flush;
	std::cout << ";deposits:" << _nbDeposits << std::flush;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}