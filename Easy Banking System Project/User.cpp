#include"User.h"
#include "MyAccount.h"
#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<ctime>
#include<limits>
#include<stdexcept>
#include<list>

User::User() {};
User::User(std::string username, double initialMoney, double initialDebt, std::string currency, std::string password): Username(username), Password(password), Account(initialMoney, initialDebt, currency) {}
std::string User::getUsername() const {
  return Username;
}
const std::string User::getPassword() const {
  return Password;
}

void User::setPassword(const std::string & password) {
  Password = password;
}

MyAccount & User::getAccount() {
  return Account;
}
const MyAccount & User::getAccount() const {
  return Account;
}
bool User::verifyPassword(const std::string & enteredPassword) const {
  return Password == enteredPassword;
}
void User::savedUserToFile(const std::string & filename) const {
  std::ofstream file(filename, std::ios::app);
  if (file.is_open()) {
    file << Username << " " << Password << '\n';
    file.close();
  } else {
    throw std::runtime_error("Failed to open file: " + filename);
  }
}