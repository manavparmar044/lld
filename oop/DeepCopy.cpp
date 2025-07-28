#include<iostream>

using namespace std;

class Test {
public:
    int* ptr;

    Test(int val) {
        ptr = new int(val);
    }

    // Custom Copy Constructor → Deep Copy
    Test(const Test& other) {
        ptr = new int(*other.ptr);  // allocate new memory
    }
};

int main() {
    Test a(10);
    Test b = a;  // deep copy

    *a.ptr = 20;
    cout << *b.ptr << endl;  // prints 10 ✅
}
