#include "User.h"
#include "functions.h"
#include "MyAccount.h"
#include "constants.h"
#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<ctime>
#include<limits>
#include<stdexcept>
#include<list>

int main() {
  try {
    std::unordered_map < std::string, User > users;
    readUsernamesFromFile(USERNAMES, users);

    std::string enteredUsername;
    std::string enteredPassword;
    bool passwordCorrect = false;
    std::unordered_map < std::string, User > ::iterator it;
    while (!passwordCorrect) {
      std::cout << "Enter your username: ";
      std::cin >> enteredUsername;

      it = users.find(enteredUsername);
      if (it == users.end()) {
        std::cout << "User not found. Creating a new user \n";
        std::cout << "Enter your password : ";
        std::cin >> enteredPassword;
        User newUser(enteredUsername, 0, 0, "", enteredPassword);
        users[enteredUsername] = newUser;
        writeUsernameToFile(USERNAMES, enteredUsername, enteredPassword);
      } else {
        std::cout << "Enter your password :";
        std::cin >> enteredPassword;
        if (it -> second.verifyPassword(enteredPassword)) {
          passwordCorrect = true;
        } else {
          std::cout << "Incorrect password. Please try again.\n";
        }
      }
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
      currentUser.savedUserToFile(USERNAMES);
      currentUser.getAccount().savedNumbers(VALUES);
    } while (choice != 8);
  } catch (const std::exception & e) {
    std::cerr << "Error occurred: " << e.what() << '\n';
  }
}