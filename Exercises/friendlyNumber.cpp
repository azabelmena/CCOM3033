/*
friendlyNumbers.cpp

A program to determine if two numbers are friendly or not. Recall two numbers m,
n are friendly if s(n)=m and s(m)=n; where s is the sum of the divisors.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

bool friendlyOrNot(int, int);

int main(){
    int num1, num2;

    //prompt the user to enter two positive integers.
    cout<< "Enter two positive integers please: ";
        cin>> num1 >> num2;

    if(num1<0 || num2<0){// if either are negative, reprompt them.
        cout<< "Please enter two integers: ";
            cin>> num1 >> num2;
    }

    if(friendlyOrNot(num1, num2)){ //if the integers are friendly, tell them they
                            // are friendly.
        cout<< num1 << " and " << num2 << " are friendly." <<endl;
    }
    else{ // else tell them they are not friendly.
        cout<< num1 << " and " << num2 << " are not friendly." <<endl;
    }

    return 0;
}

bool friendlyOrNot(int n, int m){ 
    int sum1 = 0, sum2 = 0; // the sum accumulators for n and m respectively.

    for(int i = 1; i < n; i++){ // sum all the divisors of n.
        if(n%i==0){
            sum1 += i;
        }
    }

    for(int i = 1; i < m; i++){ // sum all the divisors of m.
        if(m%i==0){
            sum2 += i;
        }
    }

    if(sum1 == m && sum2 == n){// if s(n)=m and s(m)=n, return true, m and n
        return true; // are friendly.
    }
    else{// else, return false, they are not friendly.
        return false;
    }
}
