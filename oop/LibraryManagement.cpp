#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
    private:
    string title;
    string author;
    bool isAvailable;

    public:
    Book(string t, string a) {
        title = t;
        author = a;
        isAvailable = true;
    }

    string getTitle(){
        return title;
    }

    bool available(){
        return isAvailable;
    }

    void borrowBook(){
        isAvailable = false;
    }

    void returnBook() {
        isAvailable = true;
    }

    void showInfo() {
        cout << "Title: " << title << ", Author: " << author
             << ", Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

class Member{
    private:
    string name;
    int id;
    vector<Book*> borrowedBooks;

    public:

    Member(string n,int i){
        name = n;
        id = i;
    }

    void borrow(Book* book) {
        if (book->available()) {
            book->borrowBook();
            borrowedBooks.push_back(book);
            cout << name << " borrowed \"" << book->getTitle() << "\"." << endl;
        } else {
            cout << book->getTitle() << " is not available right now." << endl;
        }
    }

    void returnAllBooks() {
        for (Book* book : borrowedBooks) {
            book->returnBook();
            cout << name << " returned \"" << book->getTitle() << "\"." << endl;
        }
        borrowedBooks.clear();
    }

    void showBorrowedBooks() {
        cout << name << "'s Borrowed Books:" << endl;
        for (Book* book : borrowedBooks) {
            book->showInfo();
        }
        if (borrowedBooks.empty()) {
            cout << "No books borrowed." << endl;
        }
    }
};

class Library{
    vector<Book*> books;
    vector<Member*> members;

    public:
    void addBook(Book *book){
        books.push_back(book);
    }
    void registerMember(Member* member) {
        members.push_back(member);
    }
    void showAllBooks() {
        cout << "\nLibrary Book List:\n";
        for (Book* book : books) {
            book->showInfo();
        }
    }
};

int main(){
    Library myLibrary;

    Book* b1 = new Book("The Alchemist", "Paulo Coelho");
    Book* b2 = new Book("C++ Primer", "Lippman");
    Book* b3 = new Book("Clean Code", "Robert Martin");

    myLibrary.addBook(b1);
    myLibrary.addBook(b2);
    myLibrary.addBook(b3);

    Member* m1 = new Member("Manav", 101);
    Member* m2 = new Member("Abhinandan", 102);

    myLibrary.registerMember(m1);
    myLibrary.registerMember(m2);

    m1->showBorrowedBooks();
    m2->showBorrowedBooks();

    m1->returnAllBooks();
    m2->returnAllBooks();

    myLibrary.showAllBooks();

    // Cleanup
    delete b1;
    delete b2;
    delete b3;
    delete m1;
    delete m2;

    return 0;
}