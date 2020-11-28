/*
Repititions Tesselations

This is the tesselations lab that goes over the repitition structure ''for'' by 
having the student program three types of tilings (a herringbone, zigzang, and 
diamond) using for loops.

Edited by: Alec Zabel-Mena.
*/

#include <QApplication>
#include <iostream>
#include <QLineEdit>
#include <QObject>
#include <QAction>
#include <QPushButton>
#include <cmath>
#include <QDebug>

#include "drawingWindow.h"
#include "tessellation.h"

/*This function tiles the simple square tile about a diagonal line, whith each 
 * subsequent sqaure rotated by 90 degrees clockwise. This also serves as the 
 * foundation to create the other tilings.*/
void foo(DrawingWindow& w) {
    int rot = 0; //set initial rotaion at 0 degrees clockwise.
    for (int i = 0; i < 4; i++) {
        Tessellation t;
        t.setRotation(rot);
        t.move(i*50, i*50); //moves the tiles along a diagonal line.
        w.addTessellation(t);
        rot += 90; //rotate the tile 90 degrees clockwise.
    }
}
/*This function creates the herringbone tiling, a common tiling in wood furniture 
 * and floor desing. It creates a ''grain'' in one direction, with what appears 
 * to be arrow (pointing in the direction of the grain) with the caveat that the 
 * arrows are split down the middle and offset by each other by 1 unit tile.*/
void herringbone(DrawingWindow& w) {
    int rot = 90; //set the initial rotation at 90 clockwise.
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++){
            Tessellation t;
            t.setRotation(rot);
            t.move(i*50, j*50); //Creates the square (or rectangle) on which the 
                                // tiling will be placed.
            w.addTessellation(t);
            rot += 180; // rotate the tiles by 180 clockwise; this will set the 
                        // position for the outermost tiles.
        }

        /*This if else statement is what will offset the tiling. Where as the 
         * outermost tiles will follow the herringbone, the middle tiles will not,
         * so it is imperative that we include this statement to be able to offset
         * the middle tiles appropriately, and creat the desired pattern.*/
        if(i%2){ //if position i is odd, the we rotate the tile 90 anticlockwise.
            rot -= 90;
        }
        else{
            rot += 90; // else we rotate 90 clockwise.
        }
    }
}
/*This function creates the zig zag tiling, using a similar method used for 
 * the herringbone tiling, exept with different rotation parameters, and the if 
 * else statement inside the nested for loop. The if else is inside the nested 
 * for loop because we need the zig zags to align parallel to the x axis.*/
void zigZag(DrawingWindow& w) {
    int rot = 180; //set initial rotation 180 clockwise, this sets the tile in 
                   // horizontal position parallel to the x axis.
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++){
            Tessellation t;
            t.setRotation(rot);
            t.move(i*50, j*50);
            w.addTessellation(t);

            if(j%2){ // if j is odd rotate 90 clockwise.
                rot += 90;
            }
            else{ //else rotate 90 anticlockwise.
                rot -= 90;
            }
        }
    rot += 180;// rotate another 180 clockwise, it is this statement (together 
               // with the if else statment that creates the zigzagging pattern.
    }
}
/*This function creates the ''diamond'' tiling, used throughout the world in many 
 * floor patterns. Like the herringbone and zigzag tilings, it follows the same 
 * comvention of different rotation parameters and uses if els statementt.
 * However, to get the desired tiling, we must use an if else statment both in 
 * the outer and nested for loops, sinc what want to do is creat one half of the 
 * tile, and then reflextt it about its diagona producing the diamond. To achieve 
 * this, we also nest additional if else statments withing the inner most if else.*/
void diamond(DrawingWindow& w){
    int rot = 0; // set initial rotation 0 clockwise.
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++){
            Tessellation t;
            t.setRotation(rot);
            t.move(i*50, j*50);
            w.addTessellation(t);

           if(i%2){ //for i and j odd, rotate 90 anticlockwise.
               if(j%2){
                    rot -= 90;
               }
               else{// for i odd and j even, rotate 90 clockwise.
                    rot += 90;
               }
           }
            else{// for i even and j odd, rotate 90 clockwise.
                if(j%2){
                    rot += 90;
                }
                else{ //for i even and j even, rotate 90 anticlockwise.
                    rot -= 90;
                }
            }

        }

        if(i%2){// if i is odd, rotate 90 anticlockwise.
            rot -= 90;
        }
        else{// else, rotate 90 clockwise.
            rot += 90;
        }

    }
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    DrawingWindow w;

    w.resize(400, 400);
    w.show();


    //foo(w);
    //herringbone(w);
    //zigZag(w);
    diamond(w);

    return a.exec();

}


