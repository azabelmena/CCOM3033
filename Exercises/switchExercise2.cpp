#include<iostream>
using namespace std;

int main(){
    
    int selection;

    cout<< "Which formula would you like to see? \n\n";
    cout<< "1. Area of a circle. \n";
    cout<< "2. Area of a rectangle.\n";
    cout<< "3. Area of a cylinder.\n";
    cout<< "4. None of them!\n -> ";
    
        cin>> selection;

    switch(selection){
        case 1: cout<< "pi*r^2\n";
                break;
        case 2: cout<< "l*w";
                break;
        case 3: cout<< "pi*r^2*h";
                break;
        case 4: cout<< "Well okay then, good bye.\n";
               break;
        default: cout<< "Not good with numbers, eh?\n";
    }


    return 0;
}
