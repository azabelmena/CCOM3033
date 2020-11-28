/*
rectTopLeft.cpp

This is the same as the squaresTopleft.cpp, except since we are working with a 
rectangle, we have the robot move east as soon as it reaches the southern boundry,
counting the squares along the east side and stroing it into a width variable.
After reaching the end, it will multiply the length (south length) and the width
(east lenght) together to get the area.

Created by: Alec Zabel-Mena.
*/
#include <QApplication>
#include "maingamewindow.h"
#include <cmath>



int main(int argc, char *argv[]) {
    QApplication   a(argc, argv);

    //MainGameWindow *w = new MainGameWindow(4,2);
    //MainGameWindow *w = new MainGameWindow("xx x\nxx x\nx xx\n");
    MainGameWindow *w = new MainGameWindow(Mode::RECT_TOP_LEFT);

    w -> show();

    w -> display("Start");

    int count1 = 1; // count the lenght of the room.
    int count2 = 1; //count the width of the room.



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
