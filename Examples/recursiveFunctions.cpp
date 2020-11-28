/*
recursiveFunctions.cpp

This program illustrates how recursive functions work.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

/*void message(int times){*/
    //if(times>0){
        //cout<< "This is a recursive function." <<endl;
        //messgage(); //this function is recursive, but goes into an infinite 
        //loop, we mitigate this by calling message(times-1)
    //}
/*}*/

void towersOfHanoi(int, int = 1, int = 2, int = 3);
void message(int);
int factorial(int);

int main(){
    int time = 5;

    message(time);

    cout<< "We now call the factorial function for n=5." <<endl
        << "5!=" <<factorial(time) <<endl;

    cout<< "We will now play the towers of Hanoi with 5 discs!" <<endl;
    cout<< "START!" <<endl;

    towersOfHanoi(time);


    return 0;
}

void message(int time){

    cout<< "This function is called with time=" << time <<".\n"; 

    if(time>0){
        cout<< "This is a recursive function." <<endl;
        message(time-1);
    }

    cout<< "This message is returning with time=" << time << ".\n";
}

int factorial(int num){
    if(num==0){
        return 1;
    }
    else{
        return num*factorial(num-1);
    }
}

void towersOfHanoi(int n, int a, int b, int c){
    if(n==0){
        cout<< "THe game has ended." <<endl; //once there are no more discs to
            //move, you have completed the towers of Hanoi.
    }
    else{
       towersOfHanoi(n-1, a, b, c);

       cout<< "Move a discs from peg " <<a<< "To peg " << c << "using peg "
           << b << " as a placeholder." <<endl;
       cout<< "Now move the remaining discs peg " << a << " to peg " << c <<endl;

       towersOfHanoi(n-1, b, a, c);
    }
}
