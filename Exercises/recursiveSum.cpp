/*
recursiveSum.cpp

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int recursiveSum(int, int);

int main(){
    int lower, upper, sum = 0;

    cout<< "Enter a lower bound: ";
        cin>> lower;

    cout<< "Enter an upper bound: ";
        cin>> upper;

    for(int i = lower; i <= upper; i++){
       sum += i; 
    }
    cout<< "Using iteration we have: " << sum << endl;
    cout<< "Using recursion we have: "<< recursiveSum(upper, lower) <<endl;

    return 0;
}

int recursiveSum(int upper, int lower){
    int sum = lower;
    if(lower == upper){
        return sum;
    }
    if(lower < upper){
       sum = lower+recursiveSum(upper,lower+1);
    }

    return sum;
}
