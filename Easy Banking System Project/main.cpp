#include "User.h"
#include "functions.h"
#include "MyAccount.h"
#include "constants.h"
#include<iostream>
#include<unordered_map>
#include<string>

//LOGICA TAKE LOAN , WITHDRAW NU MERGE 

int main() {
    try {
        std::unordered_map < std::string, User > users;
        readUsernamesFromFile(USERNAMES, users);

        std::string enteredUsername;
        std::cout << "Enter your username: ";
        std::cin >> enteredUsername;

        auto it = users.find(enteredUsername);
        if (it == users.end()) {
            User newUser(enteredUsername, 0, 0, "");
            users[enteredUsername] = newUser;
            writeUsernameToFile(USERNAMES, enteredUsername);
        }

        User & currentUser = it -> second;
        MyAccount & account = currentUser.getAccount();

        account.FileNumbers(VALUES);

        int choice;
        do {
            ShowTime();
            displayMenuHeader();
            displayMenu();
            choice = getUserChoice();
            performAction(currentUser, choice);
        } while (choice != 8);
    } catch (const std::exception & e) {
        std::cerr << "Error occurred: " << e.what() << '\n';
    }
}