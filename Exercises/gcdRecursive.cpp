/*
gcdRecursive.cpp

A way to calculate the gcd of two integers using functions and by using 
recursion.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int gcd(int, int); // the gcd function. from Z -> Z^+

int main(){

    int a, b; // integers to store the divisor and the dividend.

    cout<< "Please enter 2 integers: "; //prompt the user to enter two integers.
        cin>> a >> b;

    cout<< "gcd("<< a <<"," << b <<")=" << gcd(a,b) <<endl; // display gcd(a,b)

    return 0;
}


int gcd(int a, int b){
    // we make use of the property that gcd(a,b)=gcd(b,r), where r = a mod b.

    if(a < 0 || b < 0){ //if either arguments are negative, multiply them, 
        if(a < 0){ //respectively, by -1. This is to ensure that gcd>0 always.
            a *= -1;
        }
        if(b < 0){
            b *= -1;
        }
    }
    
    if(a%b == 0){ //if 0 = a mod b, then return b (this takes care of whether
        return b; //or not a<b), so we do not have to write a case for it.
    }

    else{
        return gcd(b, a%b); // call gcd(b,r), where r = a mod b.
    }
}
