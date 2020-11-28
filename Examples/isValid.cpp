/*
isValid.cpp

An example of how functions can return boolean variables.

Created by: Alec Zabel-Mena.
*/

#include<iostream>
using namespace std;

/*
 * Function declerations
 * */
bool isValid(int);

/*
 * Function definitions.
 * */
bool isValid(int num){
    bool status = true;

    if(num >= 1 && num <= 100){
        return status; //if true, return the default truth value (true)
    }
    else{
        status = false; //if false, set status to false and return status.

        return status;
    }
}


int main(){
    int num;

    cout<< "This program determines if a given integer is between 1 and 100.\n"
        << "Please enter an integer: ";
    
        cin>> num;

    if(isValid(num)){
        cout<< "True." <<endl;
    }
    else{
        cout<< "false." <<endl;
    }

    return 0;
}
