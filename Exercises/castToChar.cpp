//  castToChar
#include<iostream>
using namespace std;

int main(){

    char letter;

    cout<< "Please enter a letter: ";
        cin>> letter;

    cout<< "The letter, " << letter << ", has ASCII designation: "<< static_cast<int>(letter) <<endl;



























    return 0;
}
