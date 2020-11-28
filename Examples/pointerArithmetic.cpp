/*
pointerArithmetic.cpp

A program that shows how pointe arithmetic wokrks.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

const int SIZE = 8;
int main(){
    int set[SIZE] = {5, 10, 15, 20, 25, 30, 35, 40};

    int* numPtr = set;

    cout<< "The numbers in set are: ";
    for(int i = 0; i < SIZE; i++){
       cout<< *numPtr << "\t"; 

       numPtr++;
    }
    cout<<endl;

    cout<< "The numbers in set in reverse order are: ";
    for(int i = 0; i < SIZE; i++){
        numPtr--;

        cout<< *numPtr << "\t"; 
    }
    cout<<endl;

    return 0;
}
