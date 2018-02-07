// FILE: bankAccount.cpp
// AUTHOR: Cori Beemish
// DATE: 06/15/2017
// CLASS IMPLEMENTED: bankAccount.h (See bankAccount.h for documentation.)

#include "bankAccount.h"
#include <cassert>

bankAccount::bankAccount(double b, double r)
{
    assert ( b >= 0 && r >= 0);
    balance = b;
    interestRate = r;
}

double bankAccount::setBalance (double newBalance)
{
    assert (newBalance >= 0);
    balance = newBalance;
}

double bankAccount::setInterestRate (double newInterestRate)
{
    assert (newInterestRate >= 0);
    interestRate = newInterestRate;
}

void bankAccount::deposit (double amount)
{
    assert (amount >= 0);
    balance = balance + amount;
}

void bankAccount::withdrawl (double amount)
{
    assert (amount <= balance);
    balance = balance - amount;
}

void bankAccount::timeInterest (double years)
{
    assert (years >= 0);
    double temp1 = (balance * interestRate) / 100;
    double total  = temp1 * years;
    deposit(total);
}

double bankAccount::get_balance() const
{
  return balance;
}

double bankAccount::get_interestRate() const
{
  return interestRate;
}

