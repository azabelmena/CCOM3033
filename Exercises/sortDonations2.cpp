/*
sortDonations2.cpp

The sister program to sortDonations.cpp
It does the exact same thing, except that it prints
members of the sorted pointer in descending order.

author: Alec Zabel-Mena
*/
#include<iostream>
#include<vector>
using namespace std;

//--- Function declarations ----------------------------------------------------------------------------------
void selectionSort(int*[], int); // the selection sort algorithm for the pointer.
void showArray(const int[], int); // prints the contents of the array unsorted.
void showArrayPtr(int*[], int); // prints the contents of the array sorted (its pointer).
//------------------------------------------------------------------------------------------------------------

int main(){
    int numDonations; // declare the number of donations.
    int* donations = 0; // initialize the notations array to address 0 (nullptr).

    // ask the user how many donations they would like to give.
    cout<< "How many donations would you like to process? ";
        cin>> numDonations;

    // if the user enters a nonpositive ammount, tell them they are
    // rude and reprompt them.
    while(numDonations<=0){
        cout<< "You are being vary rude, please enter a positive number: ";
            cin>> numDonations;
    }

    donations = new int[numDonations]; // Dynamically allocate the donations array with 
                                        // numDonations as its size.

    int* donPtr[numDonations] = {0}; // initialize the pointer to the donations array
                                    // to be the numDonations sized array holding only the address 0
                                    // as its first member.

    // prompt the user to make their donations
    cout<< "Please enter your donations: ";
    for(int i = 0; i < numDonations ; i++){
        cin>> donations[i]; 

        //if in any of the entries there is a nonpositive ammount,
        //reprompt the user.
        while(donations[i]<=0){
            cout<< "Enter a positive ammount please: ";
                cin>> donations[i];
        }

        donPtr[i] = &donations[i]; // store the address of donations[i] in donPtr[i].
    }

    // sort the pointer to donations.
    selectionSort(donPtr, numDonations);

    // dislay the elements of donations unsorted.
    cout<< "Here are your donations unsorted:\n" <<endl;
    showArray(donations, numDonations);

    // dislay the elements of donations sorted (by dislaying the 
    // elements of donPtr).
    cout<< "\nHere are your donations sorted:\n" <<endl;
    showArrayPtr(donPtr, numDonations);

    delete [] donations; //free memory in the donations array.
    donations = 0; // reinitialize donations to address 0.

    return 0;
}

//--- Function definitions -----------------------------------------------------------------------------------
void selectionSort(int* array[], int size){ // The selection sort algorith, for donPtr.
    int scan, maxIndex;
    int* maxElement; // declarea pointer to the max element.

    for(int scan = 0; scan < size-1  ; scan++){
        maxIndex = scan; // set maxIndex to size.
        maxElement = array[scan]; // set maxElement to the scan index of array.

        for(int i = scan+1; i < size ; i++){
            if(*(array[i]) > *maxElement){ // if array[i]>maxElement
                maxElement = array[i]; // set maxElement to array[i]
                maxIndex = i; // set maxElement to i.
            }
        }

        array[maxIndex] = array[scan]; // swap the elements.
        array[scan] = maxElement;
    }
}

void showArray(const int array[], int size){ //print to contents of array.
    for(int i = 0; i < size ; i++){
        cout<< array[i] << "\t";
    }
    cout<<endl;
}

void showArrayPtr(int* array[], int size){// print the contents of the pointer to the array.
    for(int i = 0; i < size ; i++){
        cout<< *(array[i]) << "\t";
    }
    cout<<endl;
}
//------------------------------------------------------------------------------------------------------------
