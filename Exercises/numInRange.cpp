/*
numInRange.cpp

Asks the user to enter a number between 10 and 25.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int main(){

    int num;
    
    cout<< "Enter a number between 10 and 25: ";
        cin>>num;

    while(num<10 || num >25){
        cout<< "Please enter a number between 10 and 25: ";
            cin>>num;
    }

    cout<<num<<endl;

    return 0;
}
