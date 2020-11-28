/*
selectionSort.cpp

A program to demonstrate how the selection sort algoritm works.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

void selectionSort(int[], const int); // Declare the selection sort function.

const int SIZE = 7; // the constant size.
int main(){
    int array1[SIZE] = {3,1,0,4,8,2,6}, array2[SIZE] = {3,1,4,4,8,1,6};

    for(int i = 0; i < SIZE; i++){
        cout<< array1[i] << "\t";
    }
    cout<<"\n";

    for(int i = 0; i < SIZE; i++){
        cout<< array2[i] << "\t";
    }
    cout<<"\n"<<endl;


    selectionSort(array1, SIZE);
    selectionSort(array2, SIZE);


    for(int i = 0; i < SIZE; i++){
        cout<< array1[i] << "\t";
    }
    cout<<"\n";

    for(int i = 0; i < SIZE; i++){
        cout<< array2[i] << "\t";
    }
    cout<<"\n";


    
    return 0;
}

// the selection sort algorithm.
void selectionSort(int array[], const int size){
    // for init position less than 1 minus the array size.
    for(int initPosition = 0; initPosition < SIZE-1; initPosition++){
        //declare and initialize the least position and least element.
        int least = array[initPosition], leastPosition = initPosition;

        //for initposition+1 less than array size
        for(int i = initPosition+1; i < size; i++){
            if(array[i] < least){ //if the ith element is less than the least element:
                least = array[i]; // store the ith element in least
                leastPosition = i; // store the index i in the least position.
            }
        }
        //swap the array elements.
        array[leastPosition] = array[initPosition];
        array[initPosition] = least;
    }
}
