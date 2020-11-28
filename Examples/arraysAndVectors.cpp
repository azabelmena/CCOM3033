/*
arraysAndVectors.cpp

An example of how arrays and vectors work in c++.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int sumArre(int[], const int);


int main(){
// arrays are variables that store multiple values of the same type, in adjacent
// memory locations; and are initialized by appending [] to the variable name and
// specifying a size declarator.

    const int SIZE = 3; //size of the array.

    const int FILA = 3;
    const int COL = 2;

    int arre[SIZE]; // declare the array.


    double gpa[SIZE] = {3.5, 3.7, 4.0};
    string name[SIZE] = {"Laura", "Migues", "Jose"};

    for(int i = 0; i < SIZE; i++){
        cout<< "El estrudiante " <<name[i] << " Tiene un GPA de " <<gpa[i] <<endl;
    }

    for(int i = 0; i < SIZE; i++){ // fill the array with elements.
        cout<< "Enter a nunber: ";
            cin>> arre[i];
    }

    for(int i = 0; i < SIZE; i++){
        cout<< arre[i]<<" "; // display the array.
    }

    for(int& var: arre){ // how to use range based for for writing to elements.
        cin>> var;
    }


    for(int var: arre){ // the range based for loop allows us to go through
        cout<< var << ", "; // all the elements of the array without worrying 
    }   // about one off errors.

    cout<<"\narre has memory location: " << arre <<endl; //displays memory location.

    cout<< "The sum of our array elements are: " << sumArre(arre, SIZE) <<endl;

    for(int var: arre){
        cout<< var <<endl;
    }

    int scores[10][10];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            scores[i][j] = i+j;

            cout<<setw(2);
            cout<< scores[i][j] << " ";
        }

        cout<<endl;
    }

    int sum = 0;
    int notas[FILA][COL] = {{90, 85},{78, 89},{92, 95}};

    for(int i = 0; i < FILA; i++){
        for(int j = 0; j < COL; j++){
            sum += notas[i][j];
        }
    }

    cout<< sum <<endl;

    return 0;
}

int sumArre(int arre[], const int SIZE){
    int sum = 0, mayor = arre[0];

    for(int i = 0; i < SIZE; i++){
        sum += arre[i];
        arre[i] = sum+i;

        if(arre[i]>mayor){
            mayor = arre[i];
        }
    }

    return sum;
}
