/*
firstLastDigit.cpp

A program to calculat the sum of the first, and the last digit of a given integer.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<cmath>
using namespace std;

int firstLast(int);

int main(){
    int num;
    
    cout<< "Enter an integer: "; // prompt the user to enter an integer.
        cin >> num;

    cout<< "The sum of the first and last digits are: " << firstLast(num) << ".\n"; 

    return 0;
}

int firstLast(int num){
    int sum, first, tail, last, nthPower = 1, length = 0;

    length = log10(num); //find the exponential length of the number givent the base.

    if(length == 0){ // if the integer has exponential length = 0, return the twice number.
        return num+num;
    }

    for(int i = 0; i < length; i++){ //calculate the highest power of the base.
        nthPower *= 10;
    }

    if(num<0){ //if the number is negative.
        num *= -1; // make it positive.

        last = num%10; // find the last digit.

        tail = num%nthPower; // find the tail.

        first = -1*((num-tail)/nthPower); // find the first digit (and multiply)
                                    // it by -1 to make it negative.
    }
    else{ // if the number is positive;
        last = num%10; // find the last digit.

        tail = num%nthPower; // find the tail.

        first = (num-tail)/nthPower; // find the first digit.
    }

    sum = first+last; // sum the first and the last digit.

    return sum;
}
