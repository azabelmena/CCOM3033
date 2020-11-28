/*
arrayOfStructs.cpp

An example that uses arrays of structures.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
using namespace std;

struct PayInfo{
    int hours; // The hours worked.
    double payRate; // The hourly pay.
};

const int WORKERS = 3;
int main(){

    PayInfo workers[WORKERS]; // Create the array of structures.

    cout<< "Get the hours worked by the " << WORKERS << " employees "
        << " along with their hourly pay rate." <<endl;

    for(int i = 0; i <WORKERS; i++){
        cout<< "Hours worked by empolyee # " << (i+1) << ": ";
            cin>> workers[i].hours;

        cout<< "Hourly pay for empolyee # " << (i+1) << ": ";
            cin>> workers[i].payRate;

    }
    cout<<endl;

    cout<< "The gross pay for the employees is" <<endl;
    for(int i = 0; i < WORKERS; i++){
        double grossPay = workers[i].hours * workers[i].payRate;


        cout<< "Worker #" << i+1 << "\t $" << grossPay <<endl;
    }

    return 0;
}
