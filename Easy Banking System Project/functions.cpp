#include "functions.h"
#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<ctime>
#include<limits>
#include"User.h"
#include"MyAccount.h"
#define VALUES "date.txt"
#define USERNAMES "usernames.txt"
void readUsernamesFromFile(const std::string & filename,
    std::unordered_map < std::string, User > & users) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string username;
        while (file >> username) {
            users[username] = User(username, 0, 0, "");
        }
        file.close();
    }
}
void writeUsernameToFile(const std::string & filename,
    const std::string & username) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << username << '\n';
        file.close();
    }
}
void takeLoan() {
    double addDebt;
    std::cout << "Please enter the amount of your loan : " << "\n";
    std::cin >> addDebt;
    if (addDebt <= 0) {
        std::cout << "Invalid loan amount. Please enter a positive value." << '\n';
        return;
    }
}
void Withdraw(MyAccount & account) {
    double withdrawAmount;
    std::cout << "Sum of money you want to withdraw: ";
    std::cin >> withdrawAmount;
    if (withdrawAmount < 0 || withdrawAmount > account.CheckDebt()) {
        std::cout << "Invalid withdrawal amount or exceeding account balance." << '\n';
        return;
    }
    account.Withdraw(withdrawAmount);
    std::cout << " Withdrawal successful. Updated balance is : ";
    account.displayBalance();
    account.savedNumbers(VALUES);
}
void displayMenu() {
    std::cout << "\n1. Display Balance\n"
    "2. Deposit\n"
    "3. Withdraw\n"
    "4. Check if you are in debt\n"
    "5. Check currency of your money\n"
    "6. Take out a loan\n"
    "7. Pay off loan or part of your loan\n"
    "8. Exit\n"
    "Your option: ";
}
void performAction(User & currentUser, int choice) {
    MyAccount & account = currentUser.getAccount();
    enum MyMenu {
        DISPLAY_BALANCE = 1,
            DEPOSIT,
            WITHDRAW,
            CHECK_DEBT,
            CHECK_CURRENCY,
            TAKE_LOAN,
            PAY_LOAN,
            EXIT
    };
    switch (choice) {
    case DISPLAY_BALANCE:
        account.displayBalance();
        break;
    case DEPOSIT:
        double depositAmount;
        std::cout << "Sum of money you want to deposit: ";
        std::cin >> depositAmount;
        if (depositAmount < 0) {
            std::cout << "Unable to deposit a negative amount." << '\n';
            return;
        }
        account.Deposit(depositAmount);
        account.savedNumbers(VALUES);
        break;
    case WITHDRAW:
        Withdraw(account);
        break;
    case CHECK_DEBT:
        if (account.CheckDebt()) {
            std::cout << "You are in debt. Current debt is " << account.CheckDebt() << '\n';
        } else {
            std::cout << "You are debt free!";
        }
        break;
    case CHECK_CURRENCY:
        std::cout << "Currency you are using is " << account.CheckCurrency() << '\n';
        break;
    case TAKE_LOAN:
        takeLoan();
        break;
    case PAY_LOAN:
        double payDebt;
        std::cin >> payDebt; // DE TERMINAT
        break;
    case EXIT:
        std::cout << "Exiting the application...";
        break;
    default:
        std::cout << "Invalid option selected, please try again";
        break;
    }
}
int getUserChoice() {
    int choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        std::cout << "Invalid input. Please enter a valid option: ";
    }
    return choice;
}
void ShowTime() {
    time_t curr_time;
    curr_time = time(NULL);

    char * tm = ctime( & curr_time);
    std::cout << "Today is : " << tm;
}

void displayMenuHeader() {
    std::cout << "     ==== Menu ====" << '\n';
}
