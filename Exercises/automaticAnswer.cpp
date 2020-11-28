/*
automaticAnswer.cpp

The program that helps Alice answer the tapmaster

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int main(){

    int testCases, testQuestion, testAnswer; //declare variables.

    do{
        cout<< "How many test cases do you wish to evaluate? "; // ask the user
            cin>> testCases; //how many test cases they wish to process.
        for(int i = 0; i < testCases; i++){ //create a for loop to extract the
            cout<< "What question did you draw? "; //test questions for as long
                cin>> testQuestion;             //there are test cases to evalaute.

            testAnswer = ((((testQuestion*567)/9+7492)*235)/47)-498;
                        //calculate the answer (not sure how to extract the 
                        //digit in the 10s place).

            cout<< "The answer to " << testQuestion << " is: " << testAnswer
                <<endl; //display the answer.
        }
    }while(testCases);

    return 0;
}
