/*
pointersAndArrays.cpp

This program illustrates the relationship between 
pointers and arrays.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
using namespace std;

const int SIZE = 5;
int main(){
    short numbers[SIZE] = {10, 20, 30, 40, 50};

    double coins[SIZE] = {0.05, 0.1, 0.25, 0.5, 1};
    double* doublePtr = 0;

    // This shows that the name numbers is really a pointer to the array
    // declared.
    cout<< "The first address for the numbers array is " << numbers << "\n"
        << "and the first element of the numbers array is " << *numbers <<endl;

    // we can retrieve all the elementss of the array by deferencing numbers
    // in the following way:
    cout<< "We retrieve all the elements of the numbers array: ";
    for(int i = 0; i < SIZE; i++){
       cout<< *(numbers+i) << "\t"; 
    }
    cout<<endl;

    // We can also further show the relationship between pointers and arrays 
    // by using subscript notation with pointers, and using pointer notation
    // with the array.
    doublePtr = coins;

    cout<< "Here are the values in the coins array: ";
    for(int i = 0; i < SIZE; i++){
        cout<< doublePtr[i] << "\t";
    }
    cout<<endl;

    cout<< "We display the values in the coins array again: ";
    for(int i = 0; i < SIZE; i++){
        cout<< *(coins+i) << "\t";
    }
    cout<<endl;


    return 0;
}
