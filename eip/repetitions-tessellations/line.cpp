#include "line.h"
#include <QDebug>
#include <cmath>

using namespace std;

/// \fn Line::Line(QWidget *parent)
/// \~English
/// \brief Constructor sets coordinates to 0, pen color to black and pen
/// width to 1
/// \~Spanish
/// \brief Constructor que ajusta las coordenadas a 0, el color y el ancho del
/// boligrafo a negro y 1 respectivamente.
Line::Line(QWidget *parent) :
    QWidget(parent)
{
    x0 = y0 = x1 = y1 = 0;
    penColor = Qt::black;
    penWidth = 1;
}

/// \fn Line::Line(int fromX, int fromY, int toX, int toY, int w, QColor c, QWidget *parent)
/// \~English
/// \brief Constructor for a line, specifying the (fromX,fromY) and (toX,toY)
/// \param fromX starting x coordinate
/// \param fromY starting y coordinate
/// \param toX end x coordinate
/// \param toY end y coordinate
/// \param w pen width
/// \param c line color
/// \param parent parent of this line
/// \~Spanish
/// \brief Constructor de una linea, especificando las coordenadas
///  (fromX,fromY) y (toX,toY)
/// \param fromX coordenada x inicial
/// \param fromY coordenada y inicial
/// \param toX coordenada x final
/// \param toY end coordenada y final
/// \param w ancho del boligrafo
/// \param c color de la linea.
/// \param parent parent of this line
Line::Line(int fromX, int fromY, int toX, int toY, int w, QColor c, QWidget *parent):
    QWidget(parent), x0(fromX), y0(fromY), x1(toX), y1(toY), penWidth(w),  penColor(c)
{
    resize(max(x0,x1)+1,max(y0,y1)+1); 
}

/// \fn Line::Line(int fromX, int fromY, int length, double angle, int w, QColor c, QWidget *parent)
/// \~English
/// \brief Constructor for a line, specifying (fromX, fromY) and the
/// **length** and **angle**.
/// \param fromX starting x coordinate
/// \param fromY starting y coordinate
/// \param length length of the line
/// \param angle angle
/// \param w pen width
/// \param c line color
/// \param parent parent of this line
/// \~Spanish
/// \brief Constructor de una linea, especificando la coordenada
/// (fromX, fromY) and el largo (length) y el angulo (angle).
/// \param fromX coordenada x inicial
/// \param fromY coordenada y inicia
/// \param length largo de la linea
/// \param angle angulo de la linea
/// \param w ancho de la linea
/// \param c color de la linea
/// \param parent padre de esta linea
Line::Line(int fromX, int fromY, int length, double angle, int w, QColor c, QWidget *parent):
    QWidget(parent), x0(fromX), y0(fromY),  penWidth(w), penColor(c)
{
    double angleRad = M_PI * angle / 180.;
    x1 = x0 + round(length * cos(angleRad));
    y1 = y0 + round(length * sin(angleRad));
    resize(max(x0,x1)+1,max(y0,y1)+1);
}

/// \fn void Line::setCoords(int fromX, int fromY, int toX, int toY)
/// \~English
/// \brief Setter for the line coordinates
/// \param fromX starting x coordinate
/// \param fromY starting y coordinate
/// \param toX end x coordinate
/// \param toY end y coordinate
/// \~Spanish
/// \brief Ajustador de las coordenadas de la linea
/// \param fromX coordenada x inicial
/// \param fromY coordenada y inicial
/// \param toX coordenada x final
/// \param toY end coordenada y final
void Line::setCoords(int fromX, int fromY, int toX, int toY) {
    x0 = fromX;
    y0 = fromY;
    x1 = toX;
    y1 = toY;
    resize(max(x0,x1)+1,max(y0,y1)+1);
}

/// \fn void Line::setpenColor(QColor c)
/// \~English
/// \brief  Setter for the pen color
/// \param c line color
/// \~Spanish
/// \brief Ajustador del color del boligrafo
/// \param c color de la linea
void Line::setpenColor(QColor c) { penColor = c; }

/// \fn void Line::setPenWidth(int w)
/// \~English
/// \brief  Setter for the pen width
/// \param w pen width
/// \~Spanish
/// \brief Ajustador del ancho del boligrafo
/// \param w ancho de la linea
void Line::setPenWidth(int w)    { penWidth = w; }


/// \fn int Line::getX0()
/// \~English
/// \brief  Getter for the starting coordinate x.
/// \return starting coordinate x.
/// \~Spanish
/// \brief Devuelve la coordenada inicial x.
/// \return coordenada inicial x
int Line::getX0() { return x0; }

/// \fn int Line::getY0()
/// \~English
/// \brief  Getter for the starting coordinate y.
/// \return starting coordinate y.
/// \~Spanish
/// \brief Devuelve la coordenada inicial y.
/// \return coordenada inicial y
int Line::getY0() { return y0; }

/// \fn int Line::getX1()
/// \~English
/// \brief  Getter for the ending coordinate x.
/// \return ending coordinate x.
/// \~Spanish
/// \brief Devuelve la coordenada final x.
/// \return coordenada final x.
int Line::getX1() { return x1; }

/// \fn int Line::getY1()
/// \~English
/// \brief  Getter for the ending coordinate y.
/// \return ending coordinate y.
/// \~Spanish
/// \brief Devuelve la coordenada final y.
/// \return coordenada final y
int Line::getY1() { return y1; }

/// \fn void Line::paintEvent(QPaintEvent *)
/// \~English
/// \brief The paint event function is automatically invoked
/// whenever a resize or repaint happens.
/// \~Spanish
/// \brief La funcion para el evento de pintar es invocada automaticamente
/// cada ves que evento de repintar ocurre.
void Line::paintEvent(QPaintEvent *) {
    QPainter p(this);
    QPen myPen;
    myPen.setWidth(penWidth);
    myPen.setColor(penColor);

    p.setPen(myPen);
    p.drawLine(x0,y0,x1,y1);

}
