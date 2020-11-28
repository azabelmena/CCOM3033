#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H
#include <cmath>
#include <QGraphicsView>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QBitmap>
#include <QGraphicsView>
#include <genericscrollingobject.h>
//
// Constants for the types of objects. We use them to determine what collisions are
// worth processing.
//
const int RECT_MODE = 1;

class GenericScrollingObject;

typedef unsigned int uint;

enum class Mode {SQUARE_TOP_LEFT,  RECT_TOP_LEFT, RECT_RANDOM, PYRAMID_RANDOM};

class MainGameWindow: public QMainWindow {

public:

    MainGameWindow(uint rows, uint cols);
    MainGameWindow(const QString &maze);
    MainGameWindow(Mode gameMode);


    void moveRobot(char dir);
    bool canMove(char dir);

    void display(const QString &st);
    void display(int n);

private:
    QGraphicsScene *s;
    QGraphicsView  *v;
    uint _rows, _cols;

    QString _maze;
    GenericScrollingObject *robot;
    QTimer *timer;

    uint rowHeight, colWidth;
    float pct_margin;
    QGraphicsTextItem *msg;

    void paintMaze(uint initialX, uint initialY);
    void initMembers();
    bool validMaze();
    void createPiramid();
    void assignValidPos(uint &initialX, uint &initialY);
    void startTheTimer();
    void posToRC(uint &r, uint &c);
    char posToChar();
    void setMaze(const QString &maze) { _maze = maze; }

};

void delay(int ms);

#define PCT_MARGIN 0.1

#endif // MAINGAMEWINDOW_H
