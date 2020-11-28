/*
sequentialSearch.cpp

An algorithm that shows how the sequential search algorithm works.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int sequentialSearch(const int[], const int, int);

const int SIZE = 5;
int main(){
    int array[SIZE], value;

    cout<< "Enter " << SIZE << " numbers in any order: ";
    for(int i = 0; i < SIZE; i++){
        cin>> array[i];
    }

    cout<< "Enter the value you wish to search for: " <<endl;
        cin>> value;
        
     int position = sequentialSearch(array, SIZE, value);

    if(position == -1){
        cout<< "Value not found.";
    }
    else{
        cout<< "Value " << value << " found at position " << position+1 << "." <<endl;
    }

    return 0;
}

int sequentialSearch(const int array[],  const int SIZE, int value){
    int position = -1, i = 0;
    bool found = false;

    while(i< SIZE){
        if(value == array[i]){
            position = i;
        }
        i++;
    }

    return position;
}
