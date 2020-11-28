/*
sumInt.cpp

Asks the user to enter a positive integer which is added to a sum. 
The user does this until they enter a negative integer.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int main(){

    int num, sum = 0;

    cout<< "Please enter positive integers; enter a negative integer to quit.";

    while(num>0){
        cin>> num;
        sum += num;
    }

    cout<< "The sum of the integers is: " << sum-num <<endl;

    return 0;
}
