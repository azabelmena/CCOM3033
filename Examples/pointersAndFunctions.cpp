/*
pointersAndFunctions.cpp

A Program to show how pointers are used as function 
parameters.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
using namespace std;

// declare the functions that takes a pointer as an arg.
void getNumber(int*);
void getSales(double*, int);
void doubleValue(int*);
double totalSales(double*, int);

const int QTRS = 4;
int main(){

    int number;

    double sales[QTRS];

    getNumber(&number); // get the user input and store it.

    doubleValue(&number); // double the user input

    cout<< "That value doubled is: " << number <<endl;

    getSales(sales, QTRS); // get the sales data.

    cout<<fixed<<showpoint<<setprecision(2);
    cout<< "The total sales for the year are $"
        << totalSales(sales, QTRS) <<endl;

    
    return 0;
}

void getNumber(int* input){
    cout<< "Enter an integer number: ";
        cin>> *input;
}

void getSales(double* array, int size){
    for(int i = 0; i < size; i++){
        cout<< "Enter the sales figure for the quarter: " 
            << i+1 << ": ";
            cin>> array[i];
    }
}

void doubleValue(int* val){
    *val *= 2;
}

double totalSales(double* array, int size){
    double sum = 0.0;

    for(int i = 0; i < size; i++){
        sum += *array;

        array++;
    }

    return sum;
}
