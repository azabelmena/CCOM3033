/*
rectangle

The man file for the Rectangle project folder.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include"Rectangle.h" // import the Rectangle class.
#include"demo.h" // Import the demo class.
using namespace std;

int main(){
    
    Rectangle box; // Define the box instance of the rectangle.

    Demo demoObject; // define the demoObject instance of the demo class.


    double width; // declare width and length varaibles.
    double length;

    //cout<< "This program finds the area of a box." <<endl;
    //cout<< "What is the width of the box? ";
        //cin>> width;
    //cout<< "What is the length of the box? ";
        //cin>> length;

    //box.setWidth(width); // set the width and length of the box.
    //box.setLength(length);

    //cout<< "The box's width is " << box.getWidth() << "\n"
        //<< "The box's length is " << box.getLength() << "\n"
        //<< "The box's area is " << box.getArea() <<endl;

    cout<< "The following demonstrates an object with a constructor." <<endl;

    return 0;
}
