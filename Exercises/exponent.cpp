/*
exponent.cpp

A program to calculate the exponent of a given number recursively. Recall that
we define the exponent of a number a to the power n recursively as:
    (1) a^0 = 0, a^1 = 0, 0^0 is indeterminant.
    (2) a^(n+1)=a*a^n
We use this definition to calculate the exponent.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int exp(double, int); // the exponent function/

int main(){
    double base;
    int exponent;
    
    cout<<"Enter the base: "; //prompt user to enter the base
        cin>> base;
    cout<< "Enter the exponent: "; // prompt the user to enter the exponent.
        cin>> exponent;

        if(exponent < 0){ // if the exponent is negative, prompt the user to 
            cout<< "Please enter a positive exponent: "; // enter a positive
                cin>> exponent;                         // number.
        }

    if(base == 0 && exponent == 0){ // if 0^0, display indeterminant.
        cout<< "Indeterminate" <<endl;
    }

    // calculate the exponent.
    cout<< base << "^" << exponent << "=" << exp(base, exponent) <<endl;

    return 0;
}
 int exp(double base, int exponent){
    if(exponent == 0){ // if expoenent = 0, return b^0=1.
        return 1;
    }
    if(exponent == 1){ // if exponent = 1, return b^1=b.
        return base;
    }

    return base*exp(base, exponent-1); // return b*b^(exponent-1).

 }
