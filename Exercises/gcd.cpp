/*
gcd.cpp

A way to calculate the gcd of two integers

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int gcd(int, int); // the gcd function. from $Z -> Z^+$

int main(){

    int a, b; // integers to store the divisor and the dividend.

    cout<< "Please enter 2 integers: "; //prompt the user to enter two integers.
        cin>> a >> b;

    cout<< "gcd("<< a <<"," << b <<")=" << gcd(a,b) <<endl; // display gcd(a,b)

    return 0;
}


int gcd(int a, int b){
    if(!a%b){ //if a mod b = 0, do the following.
        if(b < a){ // if b<a then b|a so return b.
            return b;
        }
        else{ // if a<b, then a|b, so return a.
            return a;
        }
    }

    if(b < 0, a < 0){ //if either a or be are negative, then just multiply
        if(b<0){ // the negative valuesby -1. (gcd(-a,-b)=gcd(a,b)).
            b *= -1;
        }
        if(a<0){
            a *= -1;
        }
    }

    while(a%b > 0){ //while a mod b =/= 0, 
        int r = a%b; //set r = a mod b
        a = b; // set a = b
        b = r; // set b = a

    //interesting note is that gcd(a,b)=gcd(b,a), so gcd is a commutative map, 
    //which suggests that we should write a special case for that, however, this 
    //block of code implies commutativity; why?
    }
    return b;
}
