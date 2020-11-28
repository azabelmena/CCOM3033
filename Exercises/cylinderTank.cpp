// cylynderTank.cpp
#include<iostream>
using namespace std;

int main(){

    const double PI = 3.141592;
    
    double volume, radius, height;

    cout<< "How tall is the cylindrical tank? ";
        cin>> height;

    cout<< "What is its radius? ";
        cin>> radius;

   volume = PI*radius*radius*height;


    cout<< "The cylindrical tank has volume: " << volume <<endl;























    return 0;
}
