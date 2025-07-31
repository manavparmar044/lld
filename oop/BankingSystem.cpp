#include <iostream>
#include <vector>
using namespace std;

// ----------------- Account -----------------
class Account {
    int accountNumber;
    double balance;

public:
    Account(int accNo) {
        accountNumber = accNo;
        balance = 0.0;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "✅ Deposited Rs." << amount << ". New balance: Rs." << balance << endl;
        } else {
            cout << "❌ Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "❌ Insufficient balance.\n";
        } else if (amount <= 0) {
            cout << "❌ Invalid withdrawal amount.\n";
        } else {
            balance -= amount;
            cout << "✅ Withdrawn Rs." << amount << ". Remaining balance: Rs." << balance << endl;
        }
    }

    void showAccount() {
        cout << "🏦 Account Number: " << accountNumber << ", Balance: Rs." << balance << endl;
    }
};

// ----------------- User -----------------
class User {
    string name;
    int id;
    Account* account;

public:
    User(string name, int id, int accNo) {
        this->name = name;
        this->id = id;
        account = new Account(accNo);
    }

    void depositMoney(double amt) {
        account->deposit(amt);
    }

    void withdrawMoney(double amt) {
        account->withdraw(amt);
    }

    void showUser() {
        cout << "\n👤 User: " << name << ", ID: " << id << endl;
        account->showAccount();
    }

    int getAccountNumber() {
        return account->getAccountNumber();
    }

    ~User() {
        delete account;
    }
};

// ----------------- Bank -----------------
class Bank {
    vector<User*> users;
    int accountCounter = 1000;

public:
    void addUser(string name, int id) {
        User* u = new User(name, id, accountCounter++);
        users.push_back(u);
        cout << "✅ New user added with Account Number: " << u->getAccountNumber() << endl;
    }

    User* findUserByAccNo(int accNo) {
        for (User* u : users) {
            if (u->getAccountNumber() == accNo)
                return u;
        }
        return nullptr;
    }

    void showAllUsers() {
        cout << "\n📋 All Users:\n";
        for (User* u : users) {
            u->showUser();
        }
    }

    ~Bank() {
        for (User* u : users)
            delete u;
    }
};

int main() {
    Bank sbi;

    sbi.addUser("Manav", 1);
    sbi.addUser("Abhinandan", 2);

    User* u1 = sbi.findUserByAccNo(1000);
    User* u2 = sbi.findUserByAccNo(1001);

    if (u1) {
        u1->depositMoney(5000);
        u1->withdrawMoney(1500);
    }

    if (u2) {
        u2->depositMoney(3000);
        u2->withdrawMoney(5000); // Should show insufficient balance
    }

    sbi.showAllUsers();

    return 0;
}