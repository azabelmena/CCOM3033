/*
functionsExample.cpp

An example to show how passing arguments by reference in fucntions works.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

void getData(int&, int&);
void someFun(int&, int);

int main(){

    int num1 = 9, num2 = 12;

    cout<< "Call num1=" <<num1 << " and num2=" << num2 <<endl;
    getData(num1, num2);
    someFun(num1, num2);
    cout<< "Back in main with num1=" << num1 <<" and num2=" << num2 <<endl;

    return 0;
}

void getData(int& num1, int& num2){
    cout<< "Recibi num1=" << num1 << " y  num2=" << num2 <<endl;
    
    num1 += num2;

    cout<< "Sali con num1=" <<num1 <<endl;    
}

void someFun(int& num1, int num2){
    num1 += num2;
}
