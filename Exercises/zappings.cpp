/*
zapping.cpp

Description

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

int main(){

    int channel, channelOn, channelTo;

    do{
        cout<< "What channel are you on? ";
            cin>> channelOn;

        cout<< "What channel do you wish to go to? ";
            cin>>channelTo;

        channel = (channelTo-channelOn)%99; //evaluate the difference mod 99.
                                // which will give the number of channels the
                                // the user will change.
        /*if(channel<0){*/
            //channel *= -1; // for negative channels, multiply by -1 to have a 
                          //// positive number.
        //}
        //else if(channel == 0){
            //channel += 1; // if channel is 0, automatically add one to it.
        /*}*/

        cout<< "You are now on: " << channelTo <<". And you have swtiched "
            << " through " << channel << " channels." <<endl; //dislay the 
                    // channel the user is on, as well as how many channels
                    // they switched to.
                    //
        cout<< "To exit the program, enter -1 twice." <<endl; //give the exit
                        //condition.
    }while(channelOn != -1 && channelTo != -1);

    return 0;
}
