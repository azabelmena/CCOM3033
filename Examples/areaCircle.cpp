/*
areaCircle.cpp

A program that demonstrates the usefulness of functions by finding the area of 
a given circle.

Created by: Alec Zabel-Mena.
*/

#include<iostream>
#include<iomanip>
using namespace std;

/*
 * Function declerations
 * */

double getRadius();
double square(double);

/*
 * Function definitions
 * */
double getRadius(){
    double rad; the radius variable.

    cout<< "Enter the radius for the circle: "; ask the user to enter the circle
        cin>> rad;                               radius.

    return rad;
}

double square(double rad){
    double square = rad*rad; square the argument and store it in the variable 
                              sqaure.

    return square;
}

int main(){
    const double PI = 3.1415926;
    double radius, area;

    cout<<fixed<<showpoint<<setprecision(2); set the formatting

    cout<< "This function calculates the area of a circle." <<endl;
    
    radius = getRadius(); get the radius and store it.
    area = PI*square(radius); calculate the area.

    cout<< "The area of your circle is: " << area <<endl; display the area.

    return 0;
}
