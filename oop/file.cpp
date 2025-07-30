#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string fileName = "sample.txt";

    ofstream outFile(fileName);

    if(outFile.is_open()){
        outFile<<"Hello";
        outFile.close();
        cout<<"Data written successfully";
    }
    else{
        cout<<"File not available";
    }

    ifstream inFile(fileName);
    if(inFile.is_open()){
        string line;
        cout<<"Content";
        while(getline(inFile,line)){
            cout<<line<<endl;
        }
        inFile.close();
    }
    else{
        cout<<"File not available";
    }

    return 0;
}