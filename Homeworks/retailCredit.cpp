/*
retailCredit.cpp

A program that calculates the retail credit, based on the user's max credit, and the credit they used.

Created by: Alec Zabel-Mena

*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){

    // Declare variables to be used to calculate the credit.
    double maxCredit, usedCredit, retailCredit;

    cout<< "What is your maximum credit? "; // Ask the user their max credit.
        cin>> maxCredit;

    cout<< "How much credit have you used? "; //Ask the user how much credit they used.
        cin>> usedCredit;


    retailCredit = maxCredit-usedCredit; // Calculate the retail credit.

    cout<<"\n"; // Seperate output from the prompt.
    cout<< "Your current credit is: $" << retailCredit <<endl; // Output the retail credit.



























    return 0;
}
