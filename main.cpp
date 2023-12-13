#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <limits>
#include <unordered_map>
#include <stdexcept>
#include<ctime>
#define VALUES "date.txt"
#define USERNAMES "usernames.txt"
// IMPLEMENT ALSO A PASSWORD BESIDES USERNAME
// EACH USERNAME HAS ITS OWN INDIVIDUAL VALUES: MONEY DEBT, ETC
// EXCEPTION HANDLING IO STREAMS !!!!!!!!
// DE TERMINAT PAY LOAN
class MyAccount {
    double Money;
    double Debt;
    std::string Currency;
    std::list < std::string > Currencies;

    public:
        MyAccount() {};
    MyAccount(double money, double debt, std::string currency): Money(money), Debt(debt), Currency(currency) {
        Currencies.push_back("Euros");
        Currencies.push_back("Dollars");
        Currencies.push_back("Pounds");
        Currencies.push_back("Leu");
        if (money < 0) {
            throw std::runtime_error("Initial money cannot be lower than 0");
        }
    }

    double CheckDebt() const {
        return Debt;
    }

    void displayBalance() const {
        std::cout << "Available money in the bank is " << Money << '\n';
    }

    void Deposit(double amount) {
        Money += amount;
    }

    void Withdraw(double amount) {
        Money -= amount;
    }

    std::string CheckCurrency() const {
        return Currency;
    }

    double addDebt(double amount) {
        return Debt += amount;
    }

    //double payDebt(double amount) {}

    void FileNumbers(const std::string & date) {
        std::ifstream file(date);
        if (file.is_open()) {
            file >> Money >> Debt >> Currency;
            file.close();
        } else {
            throw std::runtime_error("Failed to open file: " + date);
        }
    }

    void savedNumbers(const std::string & date) {
        std::ofstream file(date);
        if (file.is_open()) {
            file << Money << " " << Debt << " " << Currency;
            file.close();
        } else {
            throw std::runtime_error("Failed to open file: " + date);
        }
    }
};

class User {
    std::string Username;
    MyAccount Account;

    public:
        User() {};
    User(std::string username, double initialMoney, double initialDebt, std::string currency): Username(username), Account(initialMoney, initialDebt, currency) {};

    const std::string getUsername() const {
        return Username;
    }

    MyAccount & getAccount() {
        return Account;
    }

    const MyAccount & getAccount() const {
        return Account;
    }
};

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