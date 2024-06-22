/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:52:16 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/05 08:52:16 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: 
	_accountIndex(Account::_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)    
	{
		this->_displayTimestamp();
		std::cout << "index:" << this->_accountIndex; 
		std::cout << ";amount:"<< this->_amount << ";created" << std::endl;
		_nbAccounts++;
		_totalAmount += _amount;
};

Account::~Account(void) {
	this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex; 
    std::cout << ";amount:"<< this->_amount << ";closed" << std::endl;
};

int  Account::getNbAccounts( void ) {
    return _nbAccounts;
};

int	    Account::getTotalAmount( void ) {
    return _totalAmount;
};

int	    Account::getNbDeposits( void ) {
    return _totalNbDeposits;
};

int	    Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
};

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
};

void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout <<";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount;
	this->_nbDeposits++;
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout <<";withdrawal:";
	if (withdrawal <= checkAmount()) {
		std::cout << withdrawal;
		this->_amount -= withdrawal;
		std::cout << ";amount:" << this->_amount;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
		_totalNbWithdrawals++;
		std::cout << std::endl;
		return true;
	}
	std::cout <<"refused" << std::endl;;
	return false;
}

int		Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex; 
	std::cout << ";amount:"<< this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void    Account::_displayTimestamp(void) {
	time_t secTime = time(0);

	tm *ltime = localtime(&secTime);
	char	buffer[100];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ltime);
	std::cout << buffer;
}