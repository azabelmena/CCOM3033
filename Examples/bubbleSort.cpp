/*
bubbleSort.cpp

A program to demonstrate how the bubble sort algoritm works.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

void bubbleSort(int[], const int); // Declare the bubble sort function.

const int SIZE = 7;
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


    bubbleSort(array1, SIZE);
    bubbleSort(array2, SIZE);


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

// the bubble sort algorithm.
void bubbleSort(int array[], const int size){
    bool swapped; // boolean flag

    do{
        swapped = false;
        for(int i = 0; i < size-1; i++){// loop the 1 minus the size of the array.
            if(array[i]>array[i+1]){ // if element at index i is greater than 
                swap(array[i],array[i+1]); // the element index i+1, swap.
                swapped = true; //set the swapped true.
            }
        }
    }while(swapped);
}
