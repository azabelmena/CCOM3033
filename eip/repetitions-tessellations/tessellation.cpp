#include "tessellation.h"

/// \fn Tessellation::Tessellation(QWidget *parent)
/// \~English
/// \brief Constructor. Creates a tesselation like this:
/// ![http://i.imgur.com/WuMRMsi.png](http://i.imgur.com/WuMRMsi.png)
/// \param parent  parent of this tesselation, you should pass a reference to the window
/// where this tesselation 'lives'.
/// \~Spanish
/// \brief Constructor. Crea un mosaico como este: ![http://i.imgur.com/WuMRMsi.png](http://i.imgur.com/WuMRMsi.png)
/// \param parent padre este mosaico, debes pasar una referencia a la ventana donde este mosaico 'reside'.
Tessellation::Tessellation(QWidget *parent) :
    QWidget(parent)
{
    resize(101,101);
    width = 50;
    height = 50;
    move(0,0);
    rotation = 0;
}

/// \fn int Tessellation::getRotation()
/// \~English
/// \brief Getter for the rotation.
/// \return The rotation
/// \~Spanish
/// \brief Devuelve la rotacion.
/// \return La rotacion
int Tessellation::getRotation() { return rotation; }

/// \fn int Tessellation::getWidth()
/// \~English
/// \brief Getter for the tesseltation width
/// \return tesselation width
/// \~Spanish
/// \brief Devuelve el ancho del mosaico
/// \return ancho del mosaico
int Tessellation::getWidth()    { return width; }

/// \fn int Tessellation::getHeight()
/// \~English
/// \brief Getter for the tesseltation height
/// \return tesselation height
/// \~Spanish
/// \brief Devuelve la altura del mosaico
/// \return altura del mosaico
int Tessellation::getHeight()   { return height; }


/// \fn void Tessellation::setRotation(int r)
/// \~English
/// \brief Setter for the tesselation rotation
/// \param r tessellation rotation
/// \~Spanish
/// \brief Ajusta la rotacion del mosaico
/// \param r rotacion para el mosaico
void Tessellation::setRotation(int r) { rotation = r; }

/// \fn void Tessellation::setWidth(int w)
/// \~English
/// \brief Setter for the tesselation width
/// \param w tessellation width
/// \~Spanish
/// \brief Ajusta el ancho del mosaico
/// \param w Ancho del mosaico
void Tessellation::setWidth(int w)    { width = w; }


/// \fn void Tessellation::setHeight(int h)
/// \~English
/// \brief Setter for the tesselation height
/// \param h tessellation height
/// \~Spanish
/// \brief Ajusta la altura del mosaico
/// \param h Altura del mosaico
void Tessellation::setHeight(int h)   { height = h; }


/// \fn void Tessellation::paintEvent(QPaintEvent *)
/// \~English
/// \brief Paints a tessellation in the window every time that a paint event
/// occurs.
/// \~Spanish
/// \brief Pinta un mosaico en la pantalla cada ves que ocurre un evento de
/// pintar.
void Tessellation::paintEvent(QPaintEvent *) {
    QPainter p(this);
    QPen myPen;

    myPen.setWidth(1);
    myPen.setColor(QColor(0x0000ff));
    p.setPen(myPen);

    // draw the cyan half
    p.setBrush(Qt::cyan);

    p.translate(width/2,height/2);
    p.rotate(rotation);
    p.translate(-width/2,-height/2);

    QPoint points[3];
    points[0].setX(width); points[0].setY(height);
    points[1].setX(0);   points[1].setY(height);
    points[2].setX(width); points[2].setY(0);
    p.drawPolygon(points, 3, Qt::OddEvenFill);

    // draw the blue half
    p.setBrush(Qt::blue);
    QPoint pp[3];
    pp[0].setX(0); pp[0].setY(0);
    pp[1].setX(0);   pp[1].setY(height);
    pp[2].setX(width); pp[2].setY(0);
    p.drawPolygon(pp, 3, Qt::OddEvenFill);

}
