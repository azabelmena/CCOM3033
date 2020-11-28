/*
yesOrNoTwo.cpp

Asks the user to enter a "Yes" or a "No".

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<string>
using namespace std;

int main(){

    string yesOrNo;

    cout<<"Enter Yes, or No: ";
        cin>> yesOrNo;

    while((yesOrNo != "Yes" && yesOrNo != "yes") && (yesOrNo != "No" && yesOrNo != "no")){
    
        cout<<"Please enter Yes, or No: ";
        cin>> yesOrNo;

    }

    cout<< yesOrNo <<endl;

    return 0;
}
