/*
classes.cpp

A program to illustrate what classes do.

Created by: Alec Zabel-Mena.
*/
#include<iostream>
#include<memory>
using namespace std;

class Rectangle{ // Define the rectangle class.
    private:
        double width;
        double length;

    public:
        void setWidth(double); // sets the width
        void setLength(double); // sets the length
        double getWidth() const; // gets the width
        double getLength() const; // gets the length
        double getArea() const; // gets the area
};


int main(){
    
    Rectangle box; // Define the box instance of the rectangle.

    double width; // declare width and length varaibles.
    double length;

    /*Rectangle* rectPtr = 0; // initialize a pointer that points to the rectangle class.*/
    /*rectPtr = &box; // reinitialize rectPtr to the address of box.*/

    cout<< "This program finds the area of a box." <<endl;
    cout<< "What is the width of the box? ";
        cin>> width;
    cout<< "What is the length of the box? ";
        cin>> length;

    box.setWidth(width); // set the width and length of the box.
    box.setLength(length);

    cout<< "The box's width is " << box.getWidth() << "\n"
        << "The box's length is " << box.getLength() << "\n"
        << "The box's area is " << box.getArea() <<endl;

/*    rectPtr -> setWidth(12.5);*/
    //rectPtr -> setLength(4.8);

    //cout<< "The width of the box now is: " << rectPtr -> getWidth() << "\n"
        //<< "The Length of the box now is: "<< rectPtr -> getLength() << "\n"
        //<< "The area of the box now is: " << rectPtr -> getArea() <<endl;

    //delete rectPtr; // Delete rectPtr from memory.
    /*rectPtr = 0; // reinit rectPtr to the null address.*/

/*    unique_ptr<Rectangle> rectPtr(new Rectangle);*/

    //rectPtr -> setWidth(12.5);
    //rectPtr -> setLength(4.8);

    //cout<< "The width of the box now is: " << rectPtr -> getWidth() << "\n"
        //<< "The Length of the box now is: "<< rectPtr -> getLength() << "\n"
        /*<< "The area of the box now is: " << rectPtr -> getArea() <<endl;*/

    return 0;
}

// Definition of the Memeber functions 
void Rectangle::setWidth(double w){
    if(w >= 0){
        width = w;
    }
    else{
        cout<< "Invalid width." <<endl;
        exit(1);
    }
}

void Rectangle::setLength(double l){
    if(l >= 0){
        length = l;
    }
    else{
        cout<< "Invalid width." <<endl;
        exit(1);
    }
}

double Rectangle::getWidth() const{
    return width;
}

double Rectangle::getLength() const{
    return length;
}

double Rectangle::getArea() const{
    return length * width;
}
// Definition of the Memeber functions 
