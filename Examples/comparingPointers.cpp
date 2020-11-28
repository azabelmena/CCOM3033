/*
comparingPointers.cpp

A program that shows how to compare two or more pointers.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

const int SIZE = 8;
int main(){
    int set[SIZE] = {5, 10, 15, 20, 25, 30, 35, 40};

    int* nums = set;

    // Display the numbers in the array using pointer comparison.
    cout<< "The numbers in set are: " << *nums << "\t"; // Display the first element

    while(nums < &set[SIZE-1]){
        nums++;

        cout<< * nums << "\t";
    }
    cout<<endl;

    // Display the numbers in reverse using pointer comparison.
    cout<< "The numbers in set are: " << *nums << "\t"; // Display the first element

    while(nums > set){
        nums--;

        cout<< * nums << "\t";
    }
    cout<<endl;


    return 0;
}
