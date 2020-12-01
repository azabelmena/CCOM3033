#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{ // Define the rectangle class.
    private:
        double width;
        double length;

    public:
        //Rectangle();
        //void setWidth(double); // sets the width
        //void setLength(double); // sets the length
        //double getWidth() const; // gets the width
        //double getLength() const; // gets the length
        //double getArea() const; // gets the area

        // Alternatively, we can define member functions directly to be inline.
        // Leave the lines below uncommented to use the inline functions; with 
        // the caveate that the function prototypes (above) must be commented out.
        Rectangle(){
            width = 0;
            length = 0;
        }
        void setWidth(double w){
            if(w >= 0){
                width = w;
            }
            else{
                std::cout<< "Invalid width." <<std::endl;
                exit(EXIT_FAILURE);
            }
        }
        void setLength(double l){
            if(l >= 0){
                length = l;
            }
            else{
                std::cout<< "Invalid width." <<std::endl;
                exit(EXIT_FAILURE);
            }
        }

        double getWidth() const{
            return width;
        }

        double getLength() const{
            return length;
        }

        double getArea() const{
            return length * width;
        }
};

#endif
