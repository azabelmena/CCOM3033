#include<iostream>
using namespace std;

int main(){
    
    int userNum;

    cout<< "Enter one of the following numbers: 1, 2, or, 3 -> ";
        cin>> userNum;

    switch(userNum){
        case 1: cout<< "one" <<endl;
            break;
        case 2: cout<< "two" <<endl;
               break;
        case 3: cout<< "three." <<endl;
                break;
        default: cout<< "Enter a 1, 2, or 3 please.";
    } 

    return 0;
}
