#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<ctime>
#include<limits>
#include<stdexcept>
#include<list>
#include "MyAccount.h"

class User {
  std::string Username;
  std::string Password;
  MyAccount Account;

  public:
    User();
  User(std::string username, double initialMoney, double initialDebt, std::string currency, std::string Password);
  std::string getUsername() const;
  MyAccount & getAccount();
  const MyAccount & getAccount() const;
  const std::string getPassword() const;
  void setPassword(const std::string & password);
  bool verifyPassword(const std::string & enteredPassword) const;
  void savedUserToFile(const std::string & filename) const;
};
#endif