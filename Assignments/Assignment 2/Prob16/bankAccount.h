// FILE: bankAccount.h
// AUTHOR: Cori Beemish
// DATE: 06/15/2017
//
// CLASS PROVIDED: bankAccount
//
// CONSTRUCTOR
//    bankAccount (double b = 0 , double r = 0);
//      PRECONDITION: balance (b) and rate (r) are zero.
//      POSTCONDTION: balance (b) and rate (r) are set to a new value.
//
// MODIFICATION MEMBER FUNCTIONS
//    double setBalance (double newBalance);
//        PRECONDITION: The value of newBalance is a non-negative value.
//        POSTCONDTION: The balance will be set to a new value.
//
//    double setInterestRate (double newInterestRate);
//        PRECONDITION: The value of newInterestRate is a non-negative value.
//        POSTCONDTION: The interest rate will be set to a new value.
//
//    void deposit (double amount);
//        PRECONDITION: The amount deposited into balance is a non-negative value.
//        POSTCONDTION: The balance will be increased by the amount of deposit.
//
//    void withdrawl (double amount);
//        PRECONDITION: The amount withdrawn is not larger than the current value of balance.
//        POSTCONDTION: The balance will be decreased by the value of withdrawl.
//
//    void timeInterest (double years);
//        PRECONDITION: years >= 0
//        POSTCONDTION: The interest rate will be calculated and then added to deposit.
//
// CONSTANT MEMBER FUNCTIONS
//    double get_balance() const;
//        POSTCONDTION: The value returned is the balance.
//
//    double get_interestRate() const;
//        POSTCONDTION: The value returned is the interest rate.

#ifndef BEEMISH_BANKACCOUNT_H
#define BEEMISH_BANKACCOUNT_H

#include <iostream>
#include <cassert>

class bankAccount
{

	public:
		//CONSTRUCTOR
		bankAccount (double b = 0 , double r = 0);

		// MODIFICATION MEMBER FUNCTIONS
		double setBalance (double newBalance);
		double setInterestRate (double newInterestRate);
		void deposit (double amount);
		void withdrawl (double amount);
		void timeInterest (double years);

		// CONSTANT MEMBER FUNCTIONS
		double get_balance() const;
		double get_interestRate() const;

	private:
		double balance;
		double interestRate;
};

#endif

