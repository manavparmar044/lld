#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Node structure for user
class User {
public:
    string name;
    int id;
    string email;
    User* next;

    User(int uid, string uname, string uemail) {
        id = uid;
        name = uname;
        email = uemail;
        next = nullptr;
    }
};

// Linked List to store users
class UserList {
    User* head;

public:
    UserList() {
        head = nullptr;
    }

    void addUser(int id, string name, string email) {
        if (isDuplicate(id)) {
            cout << "❌ User with ID " << id << " already exists!\n";
            return;
        }

        User* newUser = new User(id, name, email);
        if (!head) {
            head = newUser;
        } else {
            User* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newUser;
        }

        saveToFile(newUser);
        updateMetadata(newUser);
        cout << "✅ User " << name << " onboarded!\n";
    }

    bool isDuplicate(int id) {
        User* temp = head;
        while (temp) {
            if (temp->id == id) return true;
            temp = temp->next;
        }
        return false;
    }

    void updateMetadata(User* user) {
        ofstream metaFile("metadata.txt", ios::app);
        if (metaFile.is_open()) {
            metaFile << "ID: " << user->id << ", Name: " << user->name << ", Email: " << user->email << "\n";
            metaFile.close();
        } else {
            cout << "Error writing to metadata file.\n";
        }
    }

    void saveToFile(User* user) {
        string filename = "user_" + to_string(user->id) + ".txt";
        ofstream userFile(filename);
        if (userFile.is_open()) {
            userFile << "ID: " << user->id << "\n";
            userFile << "Name: " << user->name << "\n";
            userFile << "Email: " << user->email << "\n";
            userFile.close();
        } else {
            cout << "Error creating user file.\n";
        }
    }

    void displayUsers() {
        User* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Email: " << temp->email << endl;
            temp = temp->next;
        }
    }

    ~UserList() {
        User* curr = head;
        while (curr) {
            User* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    UserList ul;
    ul.addUser(101, "Alice", "alice@example.com");
    ul.addUser(102, "Bob", "bob@example.com");
    ul.addUser(101, "Duplicate", "dup@example.com"); // Will not add
    ul.addUser(103, "Charlie", "charlie@example.com");

    cout << "\n👥 All Users:\n";
    ul.displayUsers();

    return 0;
}
