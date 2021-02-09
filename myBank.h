#ifndef MYBANK_H_
#define MYBANK_H_

extern double bank[50][2];

void openAccount(double amount);
void balance(int account_number);
void deposit(int account_number, double amount);
void withdrawal(int account_number, double amount);
void closeAccount(double account_number);
void interest(double interest_rate);
void printAllAccounts();
void closeAllAccounts();

#endif