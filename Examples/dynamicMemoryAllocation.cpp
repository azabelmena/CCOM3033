/*
dynamicMemoryAllocation.cpp

In programming and software development, it is common to work with variables. 
hwoever, it is not always known how many variables a progam will need, thus dynamic 
memory allocation comes into play, and this program shows how dynamic memory allocation works 
withing C++.

This program uses the new and delete operators, which work with dynamic memory allocation, to 
total and aberage the sales figures for any number of days.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double* sales = 0, total = 0.0, average; // To dynamically allocate an array, 
                                // an accumulator, and a variable to store the
                                // average.

    int numDays;

    // Get the number of days of sales.
    cout<< "How many days of sales figures do you wish to process? ";
        cin>> numDays;

    sales = new double[numDays]; // dynamically allocate memory to sales.

    for(int i = 0; i < numDays; i++){ // Get the sales figures.
    cout<< "Day " << i+1 << ": ";
        cin>> sales[i];
    }

    for(int i = 0; i < numDays; i++){ // Calculate the total sales.
        total += sales[i];
    }

    average = total/numDays;

    // Display the total and average sales.
    cout<< fixed << showpoint << setprecision(2);
    cout<< "\nTotal sales: $" << total <<endl;
    cout<< "Average sales: $" << average <<endl;

    delete [] sales; // Free the allocated memeory and set sales to 
    sales = 0;       // the 0 memory address.

    return 0;
}
