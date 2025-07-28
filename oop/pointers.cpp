#include<iostream>

using namespace std;

int main(){
    int x = 5;
    int *p = &x;

    cout<<*p;

    int **pp = &p;

    cout<<**pp;

    // int &r = x;
    // r++;
    // cout<<x;
    return 0;
}