#include <iostream>
using namespace std;

// 🧱 Abstract base class (Abstraction)
class TrafficLight {
protected:
    string color;
    int duration; // duration in seconds

public:
    virtual void changeLight() = 0;
    virtual void showStatus() = 0;
    virtual int getDuration() = 0;

    virtual ~TrafficLight() {}
};

// 🚦 Standard traffic light (Encapsulation + Inheritance)
class StandardTrafficLight : public TrafficLight {
private:
    enum State { RED, GREEN, YELLOW };
    State currentState;

public:
    StandardTrafficLight() {
        currentState = RED;
        color = "Red";
        duration = 5;
    }

    void changeLight() override {
        if (currentState == RED) {
            currentState = GREEN;
            color = "Green";
            duration = 4;
        } else if (currentState == GREEN) {
            currentState = YELLOW;
            color = "Yellow";
            duration = 2;
        } else {
            currentState = RED;
            color = "Red";
            duration = 5;
        }
    }

    void showStatus() override {
        cout << "Current Light: " << color << " | Duration: " << duration << "s" << endl;
    }

    int getDuration() override {
        return duration;
    }
};

int main() {
    StandardTrafficLight light;

    int cycles = 5;
    for (int i = 0; i < cycles; ++i) {
        light.showStatus();   // Show current light
        light.changeLight();  // Move to next light
    }

    return 0;
}
