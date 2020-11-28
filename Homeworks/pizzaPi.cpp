/*

pizzaPi.cpp

This is a program for calculating the number of pizza slices given a pizza of some size (diameter).

Created by: Alec Zabel-Mena

*/
#include<iostream>
using namespace std;

int main(){

    const double PIZZASLICE = 14.125, PI = 3.14159265; // Define the constants for the area of a pizza slice (given in the
                                                       // book), and the circular constant pi.

    int pizzaSize; // Declare pizza size (it's diameter), as an int because no reasonable person would order a 12.5 inch
                   // pizza.
    double pizzaRadius, pizzaArea, numSlices; // Declare the pizza's radius, it's area, and the number of slices to be
                                              // calculated.

    cout<< "How large do you want your pizza? "; // Ask the user how large they want their pizza.
        cin>> pizzaSize;

    pizzaRadius = pizzaSize/2; // Calculate the number of slices.

    pizzaArea = PI*(pizzaRadius*pizzaRadius); // Sorry, but I detest using pow when I can avoid using doubles. 

    numSlices = static_cast<int>(pizzaArea/PIZZASLICE); // I static cast to int because there is no reason for the number
                                                        // of pizza slices to be a fractional number.
    
    cout<< "Your pizza will have "<< numSlices <<endl;


    return 0;
}
