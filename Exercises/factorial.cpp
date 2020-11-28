/*
factorial.cpp

A program to calculate the factorial of a given positive integer. I.e. 
factorial: Z -> Z^+. Recall that we define the factorial of a nonnegative integer
n, recursively as:
    (1) 0!=1 and 1!=1
    (2) (n+1)! = (n+1)*n!.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

long factorial(int);

int main(){
    int num;

    cout<< "Enter a positive integer: "; // enter the positvie integer.
        cin>> num;

    while(num < 0){ // if num < 0, chastize them.
        cout<< "I said enter a POSITIVE integer... you dumb bitch! ";
            cin>> num;
    }

    cout<< num << "!=" <<  factorial(num) <<endl; // calculate factorial(num)

    return 0;
}

long factorial(int n){
    if(n==0 || n == 1){ // if n = 0,1, return 1.
        return 1;
    }
    else{ //else return n*(n-1)!.
        return n*factorial(n-1);
    }
}
