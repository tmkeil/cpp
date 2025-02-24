/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:24:36 by tkeil             #+#    #+#             */
/*   Updated: 2025/02/18 12:12:11 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit) {
    this->_amount = initial_deposit;
    _accountIndex = Account::_nbAccounts;
    Account::_totalAmount += initial_deposit;
    Account::_nbAccounts++;
}

Account::~Account(void) {
    Account::_nbAccounts--;
}

bool    Account::makeWithdrawal(int withdrawal) {
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    return (true);
}

int Account::checkAmount(void) const {
    return (1);
}

void    Account::makeDeposit(int deposit) {
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
}

int  Account::getNbAccounts(void) {
    return (Account::_nbAccounts);
}

int  Account::getTotalAmount(void) {
    return (Account::_totalAmount);
}

int  Account::getNbDeposits(void) {
    return (Account::_totalNbDeposits);
}

int  Account::getNbWithdrawals(void) {
    return (Account::_totalNbWithdrawals);
}
