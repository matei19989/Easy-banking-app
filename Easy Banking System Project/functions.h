#pragma once
#include<unordered_map>
#include<string>
#include<fstream>
#include"User.h"
#include"MyAccount.h"
void readUsernamesFromFile(const std::string & filename, std::unordered_map < std::string, User > & users);
void writeUsernameToFile(const std::string & filename,
    const std::string & username);
void takeLoan();
void Withdraw(MyAccount & account);
void displayMenu();
void performAction(User & currentUser, int choice);
int getUserChoice();
void ShowTime();
void displayMenuHeader();