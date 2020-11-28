/*
pyramidRandom.cpp

Since we are wroking with an isocelese triangle, the two sides adgacent the top
most angle are equal. What this allows us to do is divide the triangle down its 
height, and then reflect one of the sides about the diagonal, what this does is
transform the triangle into a square, hence we can just count the side length we 
reflect and square it. This gives us the area of the triangle.

We however cannot do this within the program, however, since we can mathematically 
transform this triangle into a square, all we need it to find the length of one 
side (that is not the base) of the triangle.

Since the robot starts at a random position, we go about this by moving the 
robot west and south until it reaches the south western corner of the triangle. 
Once at this corner of the triangle, we move the robot one unit east, then one 
unit north, countinng one for each time the robot does this, and storing it in 
the variable count (which will store the side length).

Created by: Alec Zabel-Mena.
*/
#include <QApplication>
#include "maingamewindow.h"
#include <cmath>



int main(int argc, char *argv[]) {
    QApplication   a(argc, argv);

    //MainGameWindow *w = new MainGameWindow(4,2);
    //MainGameWindow *w = new MainGameWindow("xx x\nxx x\nx xx\n");
    MainGameWindow *w = new MainGameWindow(Mode::PYRAMID_RANDOM);

    w -> show();

    w -> display("Start");

    int count = 1; // count the length of the west side of the room

    if(w -> canMove('W')){ // If the robot can move west, move west
        while(w -> canMove('W')){
            w -> moveRobot('W');

        if(w -> canMove('S')){ //while moving west, if the robot can move south
            while(w -> canMove('S')){ // move south.
                w -> moveRobot('S');
            }
        }
        }
    }
    else{ // if the robot can move east, move east
        while(w -> canMove('S')){ // move the robot south if it can bove south.
            w -> moveRobot('S');

            while(w -> canMove('W')){ //once at the southern boundry, if the
                w -> moveRobot('W'); // robot can move west, move it west.
            }
        }
    }

    while(w -> canMove('E')){ // move the robot one unit east.
            w -> moveRobot('E');

        if(w -> canMove('N')){
            while(w -> canMove('N')){ //move the robot one unit north, and count
                w -> moveRobot('N'); // add one to the side length.
                count += 1;
            }
        }
    }


    w->display("Total: "+QString::number(count*count)); // display the total 
                        // area in the pyramid by sqauring the side length. 

    return a.exec();
}
