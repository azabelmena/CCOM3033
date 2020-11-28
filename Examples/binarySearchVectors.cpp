/*
binarySearchVecor.cpp

An algorithm that shows how the binary search algorithm works using vectors.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(const vector<int>, const int, int);

const int SIZE = 5;
int main(){
    int value;
    vector<int> array(SIZE); 

    cout<< "Enter " << SIZE << " numbers in increasing (or decreasing) order: ";
    for(int i = 0; i < SIZE; i++){
        cin>> array[i];
    }

    cout<< "Enter the value you wish to search for: ";
        cin>> value;

    int position = binarySearch(array, SIZE, value);

    if(position == -1){
        cout<< "Value not found." <<endl;
    }
    else{
        cout<< "Value " << value << " found at position " << position+1 << "." <<endl;
    }

    return 0;
}

int binarySearch(const vector<int> array,  const int SIZE, int value){
    int position = -1, first = 0, last = SIZE-1, middle;
    bool found = false;

    while(!found && first <= last){
        middle = (first+last)/2;

        if(value == array[middle]){
            found = true;

            position = middle;
        }
        else if(value > array[middle]){
            first = middle+1;
        }
        else{
            last = middle-1;
        }
    }

    return position;
}
