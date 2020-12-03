/*
sortPointers.cpp

A program that sorts the contents of an array without altering the order of the members of the array itself.
We achieve this by sorting a pointer to the array instead.
*/
#include<iostream>
using namespace std;

//--- Function declarations ----------------------------------------------------------------------------------
void selectionSort(int*[], int);
void showArray(const int[], int);
void showArrayPtr(int*[], int);
//------------------------------------------------------------------------------------------------------------

int main(){

    const int DONATIONS = 15;

    int donations[DONATIONS] = {5, 100, 5, 25, 10, 5, 25, 5, 5, 100, 10, 15, 10, 5, 10};

    int* donPtr[DONATIONS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < DONATIONS ; i++){
        donPtr[i] = & donations[i];
    }

    selectionSort(donPtr, DONATIONS);

    cout<< "Here is the original order of the array.\n" <<endl;
    showArray(donations, DONATIONS);

    cout<< "\nHere is the order of those members sorted\n" <<endl;
    showArrayPtr(donPtr, DONATIONS);

    return 0;
}

//--- Function definitions -----------------------------------------------------------------------------------
void selectionSort(int* array[], int size){
    int startScan, minIndex;
    int* minElement;

    for(int startScan = 0; startScan < size-1  ; startScan++){
        minIndex = startScan;
        minElement = array[startScan];

        for(int i = startScan+1; i < size ; i++){
            if(*(array[i]) < *minElement){
                minElement = array[i];
                minIndex = i;
            }
        }

        array[minIndex] = array[startScan];
        array[startScan] = minElement;
    }
}
void showArray(const int array[], int size){
    for(int i = 0; i < size ; i++){
        cout<< array[i] << "\t";
    }
    cout<<endl;
}
void showArrayPtr(int* array[], int size){
    for(int i = 0; i < size ; i++){
        cout<< *(array[i]) << "\t";
    }
    cout<<endl;
}
//------------------------------------------------------------------------------------------------------------

