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

    if(w -> canMove('W')){
        while(w -> canMove('W')){
            w -> moveRobot('W');

        if(w -> canMove('S')){
            while(w -> canMove('S')){
                w -> moveRobot('S');
            }
        }
        }
    }
    else{
        while(w -> canMove('S')){
            w -> moveRobot('S');

            while(w -> canMove('W')){
                w -> moveRobot('W');
            }
        }
    }

    while(w -> canMove('E')){
            w -> moveRobot('E');

        if(w -> canMove('N')){
            while(w -> canMove('N')){
                w -> moveRobot('N');
                count += 1;
            }
        }
    }


    w->display("Total: "+QString::number(count*count)); // display the total 
                    // number of rooms in the grid by displaying the area of the 
                    // pyramid.  

    return a.exec();
}
