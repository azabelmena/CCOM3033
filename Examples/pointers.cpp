/*
pointers3.cpp

Anohter program that illustrates how pointers work.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int main(){
    int x = 25; // declare and initialize some variable.

    int* ptr = 0; // This is a pointer that references an integer variable.
                 // it is initialized to the 0 memory address as to not affect
                 // any other memory addresses upon execution. In C++11, it
                 // could also be declared to nullptr, how ever for portability
                 // (and laziness) we initialise it to 0. NULL is also a valid
                 // initilization.
    
    ptr = &x; // we store the memory address of the variable x in our pointer variable.

    // Display the value, and the memory location of x.
    cout<< "The value of x is " << x <<"\n"
        << "The memory address of x is " << ptr <<endl;

    *ptr = 100; // deference the variable, i.e. alter the variable using its pointer.
                // We call the * operator the indirection operator and it
                // deferences the pointer. Note that the deference 
                // operator * is difference from the pointer 
                // decleration operator *.

    // Display the new value, and the memory location of x.
    cout<< "Now, the new value of x is " << x <<"\n"
        << "The memory address of x is still " << ptr <<endl;


    return 0;
}
