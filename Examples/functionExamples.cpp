/*
functionExample.cpp

A program that illustrates the use of functions in C++.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

/*
 * Function declerations
 */

void first();
void second();
void displayMessege();
void suma(int, int);
void resta(int, int);
void showstatic();
void displayStars(int, int);
void doubleNum(int&);

//overloaded functions
void getDimensiona(int); //the compiler will call these functions as necessary
void getDimensiona(int, int); //depending on what arguments are passed.
void getDimensiona(int, double);
void getDimensiona(double, double);

int showSum(int, int, int);

/*
 *Define displayMessege
 * */
void displayMessege(int num){
    cout<< "The value is "<< num <<endl;
}

/*
 *Define first
 * */
void first(){
    cout<< "Hello from first!" <<endl;
}

/*
 *Define second
 * */
void second(){
    cout<< "Hello from second!" <<endl;
}

/*
 *Define showSum
 * */
int showSum(int num1, int num2, int num3){
    int sum;
    sum = num1+num2+num3; //add num1, num2, and num3.

    return sum; //return the value sum
}

/*
 *Define main
 * */
int main(){
    int num1, num2, num3;
    
    cout<< "Hello from main!" <<endl;

    for(int i=0; i < 5; i++){
        displayMessege(i); //call displayMessege with argument i.
    }

    first();
    second();

    cout<< "Back in main again!" <<endl;

    /*cout<< "Now enter 3 integers: ";*/
        //cin>>num1>>num2>>num3;

    /*cout<<"The sum is: "<< showSum(num1,num2,num3) <<endl;*/

    showstatic();

    suma(5,6);

    displayStars(10,7);
    cout<<endl;
    displayStars(10,10);

    int num5 = 5;

    doubleNum(num5);

    return 0;
}

void suma(int num1, int num2){
    cout<< "Aqui num1 es: " << num1 <<endl;

    num1 += num2;

    cout<< "Todavia en suma, num1 es: " <<num1 <<endl;
}

void showstatic(){
    static int statNum;

    cout<< "This is a static variable: " << statNum <<endl;
    statNum++;
}

void displayStars(int n, int m){
    for(int i=0; i < n; i++){
        for(int j=1; j < n; j++){
            cout<< "*";
        }
        cout<<endl;
    }
}

void doubleNum(int& num){
    cout<< 2*num <<endl;
}
