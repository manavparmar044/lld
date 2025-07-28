#include<iostream>

using namespace std;

class Test{
    public:
    int *ptr;
    Test(int val){
        ptr = new int(val);
    }
};

int main(){
    Test a(10);
    Test b = a;

    *a.ptr = 20;

    cout<<*b.ptr<<endl;

    return 0;
}