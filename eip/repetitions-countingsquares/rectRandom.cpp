/*
rectRandom.cpp

The end goal is to do the same task that is done in rectTopLeft.cpp. However,
since the robot starts in a random position, we add while loops that moves the
robot to the north boundry, and then to the west boundry, bringing it to the 
top left. Once at the top left corner, the robot repeats the task in 
rectTopLeft.cpp. 

Created by: Alec Zabel-Mena.
*/
#include <QApplication>
#include "maingamewindow.h"
#include <cmath>



int main(int argc, char *argv[]) {
    QApplication   a(argc, argv);

    //MainGameWindow *w = new MainGameWindow(4,2);
    //MainGameWindow *w = new MainGameWindow("xx x\nxx x\nx xx\n");
    MainGameWindow *w = new MainGameWindow(Mode::RECT_RANDOM);

    w -> show();

    w -> display("Start");

    int count1 = 1; // count the lenght of the room.
    int count2 = 1; //count the width of the room.

    while(w -> canMove('N')){ // While the robot can move north, move the robot
       w -> moveRobot('N');   // north until the north boundry is met.
    }

    while(w -> canMove('W')){ // While the robot can move west, move the robot
       w -> moveRobot('W');   // north until the west boundry is met.
    }


    while(w -> canMove('S')){ //While moving south is possible, move the robot
        w -> moveRobot('S'); // south.
        count1 += 1;
    }

    while(w -> canMove('E')){ //While moving south is possible, move the robot
        w -> moveRobot('E'); // south.
        count2 += 1;
    }



    w->display("Total: "+QString::number(count1*count2)); // display the total 
                    // number of rooms in the grid by  multiplying the length of 
                    // the grid by the length of the grid. 

    return a.exec();
}
