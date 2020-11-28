/*
showArea.cpp

A program that further illustrates the use of functions.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

void showArea(double = 20.0, double = 10.0); // to show how predefined arguments
                    //work.
void doubleNum(int&); // How to pass arguments by reference.
void getNum(int&); // gets a number

void function(); // Used for demonstrating exit();

// we now show how overloading functions works.
int square(int); //both these functions have the same name, but they have 
double square(double); // different types and take different arguments.

int main(){
    double length, width, userFloat;
    int refVar, userNum, userInt;

    cout<<fixed<<showpoint<<setprecision(2); // formatting.

    cout<< "Please enter the lenght and width of a rectangle: ";
        cin >> length >> width;

    showArea(length, width);

    cout<< "Here is showArea with its default args: ";
    showArea();

    cout<< "Enter an integer: ";
        cin>> refVar;

    cout<< "Now here refVar is: " << refVar <<endl;
    doubleNum(refVar);

    getNum(userNum);

    doubleNum(userNum);


    cout<< "Enter an integer and a floating point please: ";
        cin>> userInt >>userFloat;
    cout<< "Here are their squares: "
        << square(userInt) << ", " << square(userFloat) <<endl;

    function();

    return 0;
}

void showArea(double length, double width){
    double area = length*width;

    cout<< "The area is " << area <<endl;
}


void doubleNum(int& refVar){
    refVar *= 2;

    cout<< "Now refVar is: " << refVar <<endl;
}

void getNum(int& value){
    cout<< "Enter a number: ";
        cin>> value;
}

int square(int num){
    return num*num;
}

double square(double num){
    return num*num;
}
void function(){
    cout<< "This program terminates with the exit function." <<endl;
    cout<< "Bye!" <<endl;

    exit(EXIT_SUCCESS); //The exit function terminates the program.

    cout<< "This messege is never displayed cause exit(0) terminated the "
        << "program." <<endl;
}
