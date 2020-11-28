/*
isEven.cpp

An example of how functions can return boolean variables.

Created by: Alec Zabel-Mena.
*/

#include<iostream>
using namespace std;

/*
 * Function declerations
 * */
bool isEven(int);

/*
 * Function definitions.
 * */
bool isEven(int num){
    bool status = true;

    if(num%2){
        status = false; //if false, set status to false and return status.

        return status;
    }
    else{
        return status; //if true, return the default truth value (true)

    }
}


int main(){
    int num;

    cout<< "This program determines if a given integer is even or odd.\n"
        << "Please enter an integer: ";
    
        cin>> num;

    if(isEven(num)){
        cout<< "even." <<endl;
    }
    else{
        cout<< "odd." <<endl;
    }

    return 0;
}
