#include<iostream>

using namespace std;

void incrementByRef(int &a){
    a++;
}

void incrementByAddress(int *ptr){
    (*ptr)++;
}

int main(){
    int a = 1;
    incrementByRef(a);
    cout<<"Value of a: "<<a<<endl;
    int *ptr = &a;
    incrementByAddress(ptr);
    cout<<"Value of a: "<<a<<endl;

    return 0;
}