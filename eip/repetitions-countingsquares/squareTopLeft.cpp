/*
squareTopLeft.cpp

This moves the robot south and counts each squae the robot moves. Since the 
robot is placed in the top left corner, the robot will count the side length 
of the square, hence it will just square the side length.

Created by: Alec Zabel-Mena.
*/
#include <QApplication>
#include "maingamewindow.h"
#include <cmath>



int main(int argc, char *argv[]) {
    QApplication   a(argc, argv);

    //MainGameWindow *w = new MainGameWindow(4,2);
    //MainGameWindow *w = new MainGameWindow("xx x\nxx x\nx xx\n");
    MainGameWindow *w = new MainGameWindow(Mode::SQUARE_TOP_LEFT);

    w -> show();

    w -> display("Start");

    int count = 1; //count the side length of the squeare.


    while(w -> canMove('S')){ //While moving south is possible, move the robot
        w -> moveRobot('S'); // south.
        count += 1;
    }


    w->display("Total: "+QString::number(count*count)); // display the total 
                    // number of rooms in the grid by sqauring the number of 
                    // rooms visited.

    return a.exec();
}
