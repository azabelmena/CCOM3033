/*
fibonacci.cpp

A program that calculates displays the Fbonacci sequence up to the n^th term.
Recall that we define the n^th FIbonacci number, recursively to be:
    (1) F_1 = 1, F_2 = 1.
    (2) F_(n+1) = F_n+F_(n-1).

The first 10 Fibonacci numbers in the sequence are:
1, 1, 2, 3 , 5, 8, 13, 21, 34, 55.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

long fibonacci(int);

int main(){
    int num;

    cout<< "Enter a positive interger: ";
        cin>> num;

    while(num < 1){
        cout<< "I said a POSITIVE integer bitch! ";
            cin >> num;
    }

    for(int i = 1; i <= num; i++){
        cout<< fibonacci(i) << ", ";
    }

    cout<<"\n";

    return 0;
}

long fibonacci(int n){
    while(n < 3){
        return 1;
    }

    do{
        return fibonacci(n-1)+fibonacci(n-2);
    }while(n>1);
}
