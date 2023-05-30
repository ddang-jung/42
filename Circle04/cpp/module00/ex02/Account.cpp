#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

Account::Account( int initial_deposit )
	:	_accountIndex(_nbAccounts++)
	,	_amount(initial_deposit)
	,	_nbDeposits(0)
	,	_nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
	_totalAmount += _amount;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount;
	++_nbDeposits;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
	_totalAmount += deposit;
	++_totalNbDeposits;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	std::cout << ";amount:" << _amount;
	++_nbWithdrawals;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	_totalAmount -= withdrawal;
	++_totalNbWithdrawals;
	return (true);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	printZeroIfSingledigit( int num ) {
	if (num < 10)
		std::cout << '0';
	std::cout << num;
}

void	Account::_displayTimestamp( void ) {
	time_t		now = time(NULL);
	struct tm	*ptr = localtime(&now);

	std::cout << '[' << ptr->tm_year + 1900;
	printZeroIfSingledigit(ptr->tm_mon + 1);
	printZeroIfSingledigit(ptr->tm_mday);
	std::cout << '_';
	printZeroIfSingledigit(ptr->tm_hour);
	printZeroIfSingledigit(ptr->tm_min);
	printZeroIfSingledigit(ptr->tm_sec);
	std::cout << "] ";
	// TEST TIMESTAMP
	// std::cout << "[19920104_091532] ";
}
