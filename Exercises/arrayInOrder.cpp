/*
arrayInOrder.cpp

A program that takes an array, and returns whether it is in ascending order.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

bool inOrder(const int[], int);

const int LENGTH = 5;
int main(){
    int A[LENGTH];
    bool inOrd;

    cout<< "Enter " << LENGTH << " integers: ";
    for(int i = 0; i< LENGTH; i++){
        cin>> A[i];
    }
    
    inOrd = inOrder(A,LENGTH);

    if(inOrd){
        cout<< "The array is in order." <<endl;
    }
    else{
        cout<< "The array is not in order." <<endl;
    }

    return 0;
}

bool inOrder(const int A[], int length){
    for(int i = 0; i < length; i++){
        if(A[i]>A[i+1]){
            return false;
        }
    }

    return true;    
}
