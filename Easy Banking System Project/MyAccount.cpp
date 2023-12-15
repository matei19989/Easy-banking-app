#include "MyAccount.h"
#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<ctime>
#include<limits>
#include<stdexcept>
#include<list>

MyAccount::MyAccount() {}
MyAccount::MyAccount(double money, double debt, std::string currency): Money(money), Debt(debt), Currency(currency) {
  Currencies.push_back("Euros");
  Currencies.push_back("Dollars");
  Currencies.push_back("Pounds");
  Currencies.push_back("Leu");
  if (money < 0) {
    throw std::runtime_error("Initial money cannot be lower than 0");
  }
}
double MyAccount::CheckDebt() const {
  return Debt;
}
void MyAccount::displayBalance() const {
  std::cout << "Available money in the bank is " << Money << '\n';
}
double MyAccount::displayOnlyBalance() const {
  return Money;
}
void MyAccount::Deposit(double amount) {
  Money += amount;
}
void MyAccount::Withdraw(double amount) {
  Money -= amount;

}
std::string MyAccount::CheckCurrency() const {
  return Currency;

}
double MyAccount::addDebt(double amount) {
  return Debt += amount;

}
void MyAccount::FileNumbers(const std::string & date) {
  try {
    std::ifstream file(date);
    if (file.is_open()) {
      file >> Money >> Debt >> Currency;
      file.close();
    } else {
      throw std::runtime_error("Failed to open file: " + date);
    }
  } catch (const std::exception & e) {
    std::cerr << "File not found" << e.what() << '\n';
  }
}
void MyAccount::savedNumbers(const std::string & date) {
  try {
    std::ofstream file(date);
    if (file.is_open()) {
      file << Money << " " << Debt << " " << Currency;
      file.close();
    } else {
      throw std::runtime_error("Failed to open file: " + date);
    }
  } catch (const std::exception & e) {
    std::cerr << "File not found" << e.what() << '\n';
  }
}