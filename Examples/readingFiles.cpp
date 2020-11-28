/*
readingFiles.cpp

A basic program to demonstrate the reading and writing of files in C++.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ofstream writeFile;
    ifstream readFile;

    writeFile.open("Employees.txt");
    readFile.open("Customers.txt");

    writeFile<< "I'm an employee! and I will bathe in the blood of the bourgoisie." <<endl;

    writeFile.close();
    readFile.close();
    return 0;
}
