// FILE: bankAccountTest.cpp
// AUTHOR: Cori Beemish
// DATE: 06/15/2017
// This is a small testing program showing how the bankAccount class is used.

#include "bankAccount.h"

int main ()
{
  bankAccount balance;
  balance.setBalance(500);
  assert (balance.get_balance() == 500);

  balance.deposit(200); //Testing deposit
  assert (balance.get_balance() == 700);

  balance.withdrawl(200);
  assert (balance.get_balance() == 500);

  balance.setInterestRate(4);
  assert (balance.get_interestRate() == 4);

  balance.timeInterest(0.5);
  assert (balance.get_balance() == 510);

  std::cout << "All tests passed!" << std::endl;
  return 0;
}
