#ifndef MY_ACCOUNT_H
#define MY_ACCOUNT_H
#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<ctime>
#include<limits>
#include<stdexcept>
#include<list>

class MyAccount {
  double Money;
  double Debt;
  std::string Currency;
  std::list < std::string > Currencies;
  public:
    MyAccount();
  MyAccount(double money, double debt, std::string currency);
  double CheckDebt() const;
  void displayBalance() const;
  void Deposit(double amount);
  void Withdraw(double amount);
  std::string CheckCurrency() const;
  double addDebt(double amount);
  void FileNumbers(const std::string & date);
  void savedNumbers(const std::string & date);
  double displayOnlyBalance() const;
  void MyAccount:: debtPayed(double amount);

};
#endif