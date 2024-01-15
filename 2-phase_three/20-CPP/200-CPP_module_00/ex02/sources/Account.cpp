/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:01:34 by lucade-s          #+#    #+#             */
/*   Updated: 2023/11/06 15:05:43 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _totalNbDeposits = 0;
    _totalNbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << (_amount + deposit) << ";nb_deposits:" << ++_nbDeposits << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
    if (_amount >= withdrawal) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << ";amount:" << _amount << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
        return true;
    } else {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
    std::string timestamp;
    std::ifstream logFile("log");
    if (logFile.is_open()) {
        std::string line;
        while (std::getline(logFile, line)) {
            if (line.find("index:" + std::to_string(_nbAccounts - 1) + ";amount:") != std::string::npos) {
                std::stringstream ss;
                ss << _nbAccounts - 1;
                timestamp = line.substr(1, 15);  // Extract the timestamp from the log entry
                break;
            }
        }
        logFile.close();
    }
    std::cout << "[" << timestamp << "]";
}
