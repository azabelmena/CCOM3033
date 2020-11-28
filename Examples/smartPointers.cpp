/*
smartPointers.cpp

A program to illustrate how smart pointers work. This is a C++11 feature, 
so portability issues may arise.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<memory> // Allows the use of smart pointers.
using namespace std;

int main(){
    int max; // the maxiumum size of the array.

    // Get the max array size.
    cout<< "How many numbers do you want to enter? ";
        cin>> max;

    unique_ptr<int[]> ptr (new int[max]); // Define a smart pointer that dynamically allocates memroy.
                                         // the smart pointer is of type unique_ptr.
    // Get the array values
    for(int i = 0; i < max; i++){
        cout<< "Enter an integer: ";
            cin>> ptr[i];
    }

    // Display the array values.
    for(int i = 0; i < max; i++){
        cout<< ptr[i] <<endl;
    }

    return 0;
}
