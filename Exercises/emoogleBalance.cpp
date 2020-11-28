/*
emmoogleBalance.cpp

We would like to find the Emoogle Balance and try and help keep our friend 
Emoogle happily married.

Created by: Alec Zabel-Mena.
*/

#include<iostream>
using namespace std;

int main(){
    int testCases, reasons, emoogleBalance; //Declare the variables to be used. 
    int emoogleDue, emooglePaid;
    
    do{

        emoogleDue = 0;
        emooglePaid = 0;
        
        cout<< "Enter the number of test cases you wish to evaluate: ";
            cin>> testCases; //promtp the user to enter how many test cases they
                            // wish to evaluate.

        cout<< "How many reasons does Emoogle have to give a treat? "; //prompt 
                        //the user for how many treats does emoogle have to give.

        for(int i = 0; i < testCases; i++){
            cin>> reasons;

            if(reasons>0 && reasons <=99){ //if there is a reason, add 1 to the
                emoogleDue += 1; //emoogle due, else add 1 to the emooglePaid
            }
            else if(reasons == 0){
                emooglePaid += 1;
            }
            else{ //If reasons is out of the [0,99] scope, print an error mesesge.
                cout<< "Please enter an integer between 0 and 99." <<endl;
            }

        emoogleBalance = emoogleDue-emooglePaid; //calculate the emoogleBalance.

        cout<< "case " << i+1 << ": "<< emoogleBalance <<endl; //display the 
                                            //emoogle balance.
                                        
        cout<< "Enter 0 to exit the program." <<endl; //displa the exit option.
        }
    }while(testCases);

    return 0;
}
