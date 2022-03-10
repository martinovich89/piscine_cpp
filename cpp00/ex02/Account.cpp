#include "Account.hpp"
#include <iostream>
#include <vector>
#include <sys/time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    struct timeval tv;
    struct timezone tz;

    gettimeofday(&tv, &tz);
    std::cout << "[" << tv.tv_sec << "_" << tv.tv_usec << "]";
}

Account::Account(void)
{
    _accountIndex = _nbAccounts;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;

    _displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;

    _displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << " ";
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::makeDeposit(int deposit)
{
    int p_amount = _amount;

    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    Account::_displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
    int p_amount = _amount;

    Account::_displayTimestamp();
    std::cout << " ";
    if (_amount - withdrawal >= 0)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
    }
    else
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << "refused\n";
    }
    return (0);
}

int		Account::checkAmount(void) const
{
    return (_amount);
}

void	Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}