#include <iostream>
#include <vector>
#include <string>
using namespace std;

// -------------------- Movie --------------------
class Movie {
    string title;
    int duration; // in minutes

public:
    Movie(string title, int duration) {
        this->title = title;
        this->duration = duration;
    }

    string getTitle() {
        return title;
    }

    int getDuration() {
        return duration;
    }

    void showDetails() {
        cout << "🎬 Movie: " << title << " (" << duration << " mins)" << endl;
    }
};

// -------------------- Screen --------------------
class Screen {
    int screenNumber;
    int totalSeats;
    Movie* movie;
    vector<bool> seats;

public:
    Screen(int number, int seatCount) {
        screenNumber = number;
        totalSeats = seatCount;
        movie = nullptr;
        seats.resize(seatCount, false); // All seats are initially empty
    }

    void assignMovie(Movie* m) {
        movie = m;
        cout << "🎞️  Movie \"" << m->getTitle() << "\" assigned to Screen " << screenNumber << endl;
    }

    bool bookSeat(int seatNo) {
        if (seatNo < 1 || seatNo > totalSeats) {
            cout << "❌ Invalid seat number.\n";
            return false;
        }
        if (seats[seatNo - 1]) {
            cout << "❌ Seat " << seatNo << " is already booked.\n";
            return false;
        }
        seats[seatNo - 1] = true;
        cout << "✅ Seat " << seatNo << " booked successfully on Screen " << screenNumber << endl;
        return true;
    }

    void showSeatStatus() {
        cout << "🪑 Seat Status for Screen " << screenNumber << ": ";
        for (int i = 0; i < totalSeats; i++) {
            cout << (seats[i] ? "[X]" : "[ ]");
        }
        cout << endl;
    }

    Movie* getMovie() {
        return movie;
    }

    int getScreenNumber() {
        return screenNumber;
    }
};

// -------------------- User --------------------
class User {
    string name;
    int id;

public:
    User(string name, int id) {
        this->name = name;
        this->id = id;
    }

    void showUser() {
        cout << "👤 User: " << name << " (ID: " << id << ")" << endl;
    }
};

// -------------------- Theater --------------------
class Theater {
    vector<Screen*> screens;

public:
    void addScreen(Screen* s) {
        screens.push_back(s);
    }

    void listMovies() {
        cout << "\n📽️ Available Movies in Theater:\n";
        for (Screen* s : screens) {
            if (s->getMovie() != nullptr) {
                cout << "Screen " << s->getScreenNumber() << ": ";
                s->getMovie()->showDetails();
            }
        }
    }

    Screen* getScreen(int screenNo) {
        for (Screen* s : screens) {
            if (s->getScreenNumber() == screenNo) {
                return s;
            }
        }
        return nullptr;
    }

    ~Theater() {
        for (Screen* s : screens) {
            delete s;
        }
    }
};

// -------------------- BookingSystem --------------------
class BookingSystem {
public:
    void book(User* user, Theater* theater, int screenNo, int seatNo) {
        cout << "\n🧾 Booking Request...\n";
        user->showUser();

        Screen* s = theater->getScreen(screenNo);
        if (!s) {
            cout << "❌ Screen not found.\n";
            return;
        }

        Movie* m = s->getMovie();
        if (!m) {
            cout << "❌ No movie assigned to this screen.\n";
            return;
        }

        cout << "🎬 Booking for movie: " << m->getTitle() << " on Screen " << screenNo << endl;
        bool success = s->bookSeat(seatNo);
        if (success) {
            cout << "🎟️ Booking Confirmed!\n";
        }
    }
};


int main() {
    // Create some movies
    Movie* m1 = new Movie("Inception", 148);
    Movie* m2 = new Movie("Oppenheimer", 180);

    // Create screens and assign movies
    Screen* s1 = new Screen(1, 10);
    Screen* s2 = new Screen(2, 8);
    s1->assignMovie(m1);
    s2->assignMovie(m2);

    // Create theater and add screens
    Theater t;
    t.addScreen(s1);
    t.addScreen(s2);

    // Create users
    User* u1 = new User("Manav", 101);
    User* u2 = new User("Ayesha", 102);

    // Show all movies
    t.listMovies();

    // Booking system
    BookingSystem system;
    system.book(u1, &t, 1, 4); // Book seat 4 on screen 1
    system.book(u2, &t, 2, 4); // Book seat 4 on screen 2
    system.book(u2, &t, 1, 4); // Try to book already booked seat

    // Show seat maps
    s1->showSeatStatus();
    s2->showSeatStatus();

    // Clean up
    delete m1;
    delete m2;
    delete u1;
    delete u2;

    return 0;
}
