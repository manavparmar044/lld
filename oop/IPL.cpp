#include <iostream>
#include <vector>
using namespace std;

// ------------- Player Class -------------
class Player {
    string name;
    int jerseyNumber;
    string role;

public:
    Player(string name, int jersey, string role) {
        this->name = name;
        this->jerseyNumber = jersey;
        this->role = role;
    }

    void showInfo() {
        cout << "👕 " << name << " | Jersey: " << jerseyNumber << " | Role: " << role << endl;
    }
};

// ------------- Team Class -------------
class Team {
    string name;
    string owner;
    vector<Player*> players;

public:
    Team(string name, string owner) {
        this->name = name;
        this->owner = owner;
    }

    void addPlayer(Player* p) {
        players.push_back(p);
    }

    void showTeam() {
        cout << "\n🏏 Team: " << name << " | Owner: " << owner << endl;
        cout << "Players:\n";
        for (Player* p : players) {
            p->showInfo();
        }
    }

    ~Team() {
        for (Player* p : players)
            delete p;
    }
};

// ------------- Main Function -------------
int main() {
    Team mi("Mumbai Indians", "N. Ambani");

    mi.addPlayer(new Player("Rohit Sharma", 45, "Batsman"));
    mi.addPlayer(new Player("Surya Kumar Yadav", 63, "Batsman"));
    mi.addPlayer(new Player("Jasprit Bumrah", 93, "Bowler"));

    mi.showTeam();

    return 0;
}
