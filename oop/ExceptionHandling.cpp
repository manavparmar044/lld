#include <iostream>
using namespace std;

int divide(int a, int b) {
    if (b == 0)
        throw "Division by zero error!";
    return a / b;
}

int main() {
    int x = 10, y = 0;

    try {
        cout << "Result: " << divide(x, y) << endl;
    } catch (const char* msg) {
        cout << "Caught Exception: " << msg << endl;
    }

    return 0;
}
