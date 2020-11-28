#include "genericscrollingobject.h"
#include "maingamewindow.h"
#include <QDebug>

//
// A class for the items that move.

GenericScrollingObject::GenericScrollingObject(const std::string& filename, QGraphicsScene *scene,
                                               int x, int y, int w, int h,
                                               const QColor& transparency_color ,
                                               MainGameWindow *parent
                                               )
{
    scene->addItem(this);
    myScene = scene;
    alive = true;

    // create a pixmap with invisible background
    QPixmap pixmap(filename.c_str());
    pixmap = pixmap.scaled(w,h);
    const QBitmap mask = pixmap.createMaskFromColor(transparency_color);
    pixmap.setMask(mask);
    this->setPixmap(pixmap);

    // set position and speed
    myX = x;
    myY = y;
    toX = toY = 0;
    myDirY = 0;
    myDirX = 0;
    myParent = parent;
    setPos(myX,myY);
}


//
// This method that is automatically called on each tick
//
void GenericScrollingObject::advance(int) {

    myX = myX + myDirX;
    myY = myY + myDirY;

    if (myDirX != 0 && abs(myX-toX) < 10) { myDirX = 0; myX = toX;}
    if (myDirY != 0 && abs(myY-toY) < 10) { myDirY = 0; myY = toY;}
    
    this->setPos(myX,myY);
}


void GenericScrollingObject::kill() {
    alive = false;

    // Show the explosion, instead of the robot
    QPixmap pixmap(":explosion.png");
    pixmap = pixmap.scaled(boundingRect().width(),boundingRect().height(),Qt::IgnoreAspectRatio,Qt::FastTransformation);

    const QBitmap mask = pixmap.createMaskFromColor(QColor(Qt::black));
    pixmap.setMask(mask);

    setPixmap(pixmap);
}





