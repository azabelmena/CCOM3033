#ifndef LINE_H
#define LINE_H

#include <QWidget>
#include <QPainter>

/// \~English
/// A class to describe lines.
/// \~Spanish
/// Una clase para describir lineas
class Line : public QWidget
{
    Q_OBJECT
public:

    /// \fn Line::Line(QWidget *parent)
    /// \~English
    /// \brief Constructor sets coordinates to 0, pen color to black and pen
    /// width to 1
    /// \~Spanish
    /// \brief Constructor que ajusta las coordenadas a 0, el color y el ancho del
    /// boligrafo a negro y 1 respectivamente.
    explicit Line(QWidget *parent = 0);

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
    Line(int fromX, int fromY, int toX, int toY, int w, QColor c, QWidget *parent = 0);

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
    Line(int fromX, int fromY, int length, double angle, int w, QColor c, QWidget *parent = 0);

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
    void setCoords(int fromX, int fromY, int toX, int toY);

    /// \fn void Line::setpenColor(QColor c)
    /// \~English
    /// \brief  Setter for the pen color
    /// \param c line color
    /// \~Spanish
    /// \brief Ajustador del color del boligrafo
    /// \param c color de la linea
    void setpenColor(QColor c);

    /// \fn void Line::setPenWidth(int w)
    /// \~English
    /// \brief  Setter for the pen width
    /// \param w pen width
    /// \~Spanish
    /// \brief Ajustador del ancho del boligrafo
    /// \param w ancho de la linea
    void setPenWidth(int w);

    /// \fn int Line::getX0()
    /// \~English
    /// \brief  Getter for the starting coordinate x.
    /// \return starting coordinate x.
    /// \~Spanish
    /// \brief Devuelve la coordenada inicial x.
    /// \return coordenada inicial x
    int getX0();

    /// \fn int Line::getY0()
    /// \~English
    /// \brief  Getter for the starting coordinate y.
    /// \return starting coordinate y.
    /// \~Spanish
    /// \brief Devuelve la coordenada inicial y.
    /// \return coordenada inicial y
    int getY0();

    /// \fn int Line::getX1()
    /// \~English
    /// \brief  Getter for the ending coordinate x.
    /// \return ending coordinate x.
    /// \~Spanish
    /// \brief Devuelve la coordenada final x.
    /// \return coordenada final x.
    int getX1();

    /// \fn int Line::getY1()
    /// \~English
    /// \brief  Getter for the ending coordinate y.
    /// \return ending coordinate y.
    /// \~Spanish
    /// \brief Devuelve la coordenada final y.
    /// \return coordenada final y
    int getY1();

signals:

public slots:

protected:
    /// \fn void Line::paintEvent(QPaintEvent *)
    /// \~English
    /// \brief The paint event function is automatically invoked
    /// whenever a resize or repaint happens.
    /// \~Spanish
    /// \brief La funcion para el evento de pintar es invocada automaticamente
    /// cada ves que evento de repintar ocurre.
    void paintEvent(QPaintEvent *);

private:
    int x0, /**< initial coord x  / coordenada inicial x */
    y0,     /**< initial coord y / coordenada inicial y */
    x1,     /**< ending coord x / coordenada final x */
    y1;     /**< ending coord y / coordenada final y */
    int penWidth; /**< pen width / ancho del boligrafo */
    QColor penColor; /**< pen color / color del boligrafo */

};

#endif // LINE_H
