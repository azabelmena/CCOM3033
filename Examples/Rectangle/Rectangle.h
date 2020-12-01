#ifndef RECTANGLE_H
#define RECTANGLE_H

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

#endif
