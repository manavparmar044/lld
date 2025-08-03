#include<iostream>
using namespace std;

class Box {
private:
    int width;

public:
    Box() : width(10) {}

    friend void printWidth(Box b);
};

void printWidth(Box b) {
    cout << "Width is: " << b.width << endl;
}

int main() {
    Box b;
    printWidth(b);
    return 0;
}
