/*
payRollStructs.cpp

A program that shows how to use structures.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<string>
using namespace std;

// The PayRoll struct describes employee data
struct PayRoll{
    int empId; // The Employee's ID numbers.
    string name; // Name of the employee.
    double hours; // The hours the employee worked.
    double payRate; // The pay rate for the employee.
    double grossPay; // The employee's gross pay.
};

int main(){

    PayRoll Employee; // Describes the employee using the PayRoll struct.

    cout<< "Please enter your employee ID: ";
        cin>>  Employee.empId;

    cout<< "Please enter your name: ";
        cin>>  Employee.name;

    cout<< "Enter the hours worked: ";
        cin>>  Employee.hours;

    cout<< "Enter your hourly pay: ";
        cin>>  Employee.payRate;

    Employee.grossPay = Employee.hours * Employee.payRate;

    cout<< "The gross pay for " << Employee.name << " is $" << Employee.grossPay <<endl;

    return 0;
}
