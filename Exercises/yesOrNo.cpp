/*
yesOrNo.cpp

Asks the user to enter a 'Y', 'y' or a 'N', 'n'.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int main(){

    char yesOrNo;

    cout<<"Enter Y for yes, or N for n: ";
        cin>> yesOrNo;

    while((yesOrNo != 'Y' && yesOrNo != 'y') && (yesOrNo != 'N' && yesOrNo != 'n')){
    
        cout<<"Please enter Y for yes, or N for n: ";
        cin>> yesOrNo;

    }

    cout<< yesOrNo <<endl;

    return 0;
}
