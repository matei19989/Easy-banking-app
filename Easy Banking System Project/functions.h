#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<ctime>
#include<limits>
#include<stdexcept>
#include<list>
#include"User.h"
#include"MyAccount.h"

void readUsernamesFromFile(const std::string & filename, std::unordered_map < std::string, User > & users);
void writeUsernameToFile(const std::string & filename,
  const std::string & username,
    const std::string & password);
void takeLoan(MyAccount & account);
void Withdraw(MyAccount & account);
void displayMenu();
void performAction(User & currentUser, int choice);
int getUserChoice();
void ShowTime();
void displayMenuHeader();
#endif