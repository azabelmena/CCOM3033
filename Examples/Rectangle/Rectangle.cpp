#include<iostream>
#include<cstdlib>
#include"Rectangle.h" // includes the Rectangle class.
using namespace std;

void Rectangle::setWidth(double w){
    if(w >= 0){
        width = w;
    }
    else{
        cout<< "Invalid width." <<endl;
        exit(EXIT_FAILURE);
    }
}

void Rectangle::setLength(double l){
    if(l >= 0){
        length = l;
    }
    else{
        cout<< "Invalid length." <<endl;
        exit(EXIT_FAILURE);
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

