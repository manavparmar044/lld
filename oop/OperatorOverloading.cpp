#include <iostream>
using namespace std;

class Complex {
    int real;
    int imag;

public:
    // Constructor
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Overload + operator
    Complex operator + (const Complex& other) {
        Complex result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }

    // Display function
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3);      // 2 + 3i
    Complex c2(1, 4);      // 1 + 4i
    Complex c3 = c1 + c2;  // calls overloaded +

    c3.display();          // Output: 3 + 7i
    return 0;
}
