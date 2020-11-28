/*
circStruct.cpp

More examples how to use structs.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
using namespace std;

const int PI = 3.1415926; // set the pi constant.

struct Circle{
    double radius; // the radius of the circle.
    double diameter;// the diameter of the circle.
    double area; // the area of the circle.
};

int main(){
    Circle c; // Declare a circle.

    cout<< "Enter the radius of the circle: ";
        cin>> c.radius;

    c.diameter = 2*c.radius; // Calculate the diameter of the circle.
    c.area = PI*(c.radius*c.radius); // Find the area of the circle.

    cout<< "The circle, c, of radius: " << c.radius << " has diameter " 
        << c.diameter << " and has area " << c.area <<endl;

    return 0;
}
