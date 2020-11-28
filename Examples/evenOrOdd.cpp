/*
modulus.cpp

A simple program that evaluates whether a given integer is even or odd (note this
includes ASCII characters).

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int main(){
    int parity, num;

    cout<< "Enter an integer number: ";
        cin>> num;

    parity = num % 2;

    if(parity){
        cout<< "The number you entered is odd." <<endl;
    }
    else if(!parity){
        cout<<"The number you entered is even." <<endl;
    }

    else{
        cout<<"Please enter an integer number." <<endl;
    }

    return 0;
}
