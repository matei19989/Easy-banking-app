#include"User.h"
#include "MyAccount.h"
#include<iostream>
#include<string>

User::User() {};
User::User(std::string username, double initialMoney, double initialDebt, std::string currency): Username(username), Account(initialMoney, initialDebt, currency) {}
std::string User::getUsername() const {
    return Username;
}
MyAccount & User::getAccount() {
    return Account;
}
const MyAccount & User::getAccount() const {
    return Account;
}