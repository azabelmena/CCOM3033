/*
perfectNumber.cpp

A program that determines whether a given number is perfect. Recall that a 
positive integer n is perfect if the sum of its devisors is 2n.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

bool perfect(int);

int main(){
    int num;

    cout<< "Enter a positive integer: "; // prompt the user to enter a 
        cin>> num;                      // positive integer.

    while(num<=0){ // if they enter negative, reprompt them to enter positive.
        cout<< "Please enter a positive integer: ";
            cin>> num;
    }

    if(perfect(num)){ // if n is a perfect number, tell them that it is perfect.
        cout<< num << " is perfect." <<endl;
    }
    else{ // if n is not perfect, tell them that it is not perfect.
         cout<< num << " is not perfect." <<endl;
    }

    return 0;
}

bool perfect(int num){
    int sum = 0;

    for(int i = 1; i <= num; i++){ // sum all the divisors of n.
        if(num%i == 0){
            sum += i;
        }
    }

    if(sum == 2*num){ // if the sum is 2n, return true, n is a perfect number.
        return true;
    }
    else{ //else return false, n is not perfect.
        return false;
    }
}

