#ifndef GENERICSCROLLINGOBJECT_H
#define GENERICSCROLLINGOBJECT_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QBitmap>


// A class for the items that move.

class MainGameWindow;

class GenericScrollingObject : public QGraphicsPixmapItem {
public:
    GenericScrollingObject(const std::string& filename, QGraphicsScene *scene,
                           int x, int y, int w, int h,
                           const QColor& transparency_color = QColor(0,255,0),
                           MainGameWindow *parent = 0
            );

    int x() const { return myX; }
    int y() const { return myY; }

    //
    // This method that is automatically called on each tick
    //
    void advance(int phase);


    // given an integer number of pixels, move the item by that amount, vertically
    void kill();
    bool isAlive() {return alive;}
    int myDirX, myDirY;
    int myX, myY;
    int toX, toY;

private:
    bool alive;
    QGraphicsScene *myScene;
    MainGameWindow *myParent;
};




#endif // GENERICSCROLLINGOBJECT_H
