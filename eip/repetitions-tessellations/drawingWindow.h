#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "tessellation.h"
#include "line.h"


using namespace std;
namespace Ui {
class DrawingWindow;
};

/// \~English
/// A class to create a drawing window to draw tessellations.
/// \~Spanish
/// Una clase para crear una ventana de dibujos para dibujar mosaicos
class DrawingWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// \fn DrawingWindow::DrawingWindow(QWidget *parent)
    /// \~English
    /// \brief Constructor
    /// \~Spanish
    /// \brief Constructor
    explicit DrawingWindow(QWidget *parent = 0);

    /// \fn DrawingWindow::~DrawingWindow()
    /// \~English
    /// \brief Destructor
    /// \~Spanish
    /// \brief Destructor
    ~DrawingWindow();

    /// \fn void DrawingWindow::addTessellation(Tessellation &t)
    /// \~English
    /// \brief Add a tessalation to the window
    /// \param t  a tessellation object
    /// \~Spanish
    /// \brief Anade un mosaico a la ventana
    /// \param t un objeto de tipo tessellation (mosaico)
    void addTessellation(Tessellation &t);

    /// \fn void DrawingWindow::addLine(int x0, int y0, int x1, int y1, int width, QColor color)
    /// \~English
    /// \brief Add a line to the window, specifying coordinates
    /// of the starting and end points.
    /// \param x0  starting coordinate x
    /// \param y0  starting coordinate y
    /// \param x1  end coordinate x
    /// \param y1  end coordinate y
    /// \param width line width
    /// \param color line color
    /// \~Spanish
    /// \brief Anade una linea a la ventana, especificando las coordenadas
    /// de los puntos iniciales y finales
    /// \param x0  coordenada inicial x
    /// \param y0  coordenada inicial y
    /// \param x1  coordenada final x
    /// \param y1  coordenada final y
    /// \param width ancho de la linea
    /// \param color color de la linea
    void addLine(int x0, int y0, int x1, int y1, int width, QColor color);

    /// \fn void DrawingWindow::addLinePolar(int x0, int y0, int length, double angle, int width, QColor color)
    /// \~English
    /// \brief Add a line to the window, specifying coordinates
    /// of the starting point, the length and angle.
    /// \param x0  starting coordinate x
    /// \param y0  starting coordinate y
    /// \param length - length of the line
    /// \param angle - angle of the line
    /// \param width - line width
    /// \param color - line color
    /// \~Spanish
    /// \brief Anade una linea a la ventana, especifica las coordenadas
    /// de  el punto inicial, el largo y el angulo
    /// \param x0  coordenada inicial x
    /// \param y0  coordenada inicial y
    /// \param length - largo de la linea
    /// \param angle - angulo de la linea
    /// \param width - ancho de la linea
    /// \param color - color de la linea
    void addLinePolar(int x0, int y0, int length, double angle, int width, QColor color);
private:
    Ui::DrawingWindow *ui;
    vector <Tessellation* > *vT; /**< vector of tesselation / vector de mosaicos */
    vector <Tessellation *> *myTessellation; /**< vector of tesselation / vector de mosaicos */
    vector <Line *> *vL;  /**< vector of line / vector de lineas */

protected:
    /// \fn void DrawingWindow::paintEvent(QPaintEvent *)
    /// \~English
    /// \brief Paints event.
    /// \~Spanish
    /// \brief Evento de pintar
    void paintEvent(QPaintEvent *);
};

#endif // MAINWINDOW_H
