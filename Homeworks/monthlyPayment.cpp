/*
monthlyPayment.cpp

This program ask for a loan ammount, an interest rate, and displays a ledger for the monthly payment.

Created by: Alec Zabel-Mena.

*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){

    // declare the variables to be used.
    double loan, annualRate, rate, payNum, payment, ammountPaid, interestPaid;

    //Ask the user to input their loan, their annual interest rate, and how many times they've paid

    cout<<"How much did you take on loan? ";
        cin>> loan;

    cout<<"What is your annual interest rate? ";
        cin>> annualRate;

    cout<< "How many payments have you made? ";
        cin>> payNum;

    // Calculate their rate, their monthly payment, how much they paid back, and how much was paid in interest.

    rate = annualRate/12.0;

    payment = loan*((rate*pow(1+rate, payNum))/(pow(1+rate, payNum)-1));

    ammountPaid = payment*payNum;

    interestPaid = ammountPaid*rate;

    // Display their ledger, formatted appropriately.
    
    cout<<"\n"; //seperates the ledger display from the prompt.
    cout<<"Loan Ammount: "<<setw(15)<<"$ "<<setw(1)<< loan<<endl;

    cout<<"Monthly Interest rate:  "<<setw(9)<< rate <<"%" <<endl;

    cout<<"Number of payments:  "<<setw(8)<<"$ "<<setw(1)<< payNum <<endl;

    cout<<"Monthly Paynent:  "<<setw(11)<<"$ "<<setw(1)<< payment <<endl;

    cout<<"Ammount Paid Back: "<<setw(10)<<"$ "<<setw(1)<< ammountPaid <<endl;

    cout<<"Interest Paid:  "<<setw(13)<<"$ "<<setw(1)<< interestPaid <<endl;


    return 0;
}
