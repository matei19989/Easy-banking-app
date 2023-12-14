#pragma once
#include<string>
#include "MyAccount.h"
class User{
std::string Username;
    MyAccount Account;

    public:
        User();
    User(std::string username, double initialMoney, double initialDebt, std::string currency);
    std::string getUsername() const;
    MyAccount & getAccount();
    const MyAccount & getAccount() const;
};
    