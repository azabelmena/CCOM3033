#include "drawingWindow.h"
#include "ui_drawingWindow.h"
#include <vector>

/// \fn DrawingWindow::DrawingWindow(QWidget *parent)
/// \~English
/// \brief Constructor.
/// \~Spanish
/// \brief Constructor.
DrawingWindow::DrawingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawingWindow)
{
    ui->setupUi(this);
    myTessellation = new vector<Tessellation *>;
    vT = new vector<Tessellation *>;
    vL = new vector<Line *>;

    // just hidding the toolbars to have a bigger drawing area.
    QList<QToolBar *> toolbars = this->findChildren<QToolBar *>();
    foreach(QToolBar *t, toolbars) t->hide();
    QList<QStatusBar *> statusbars = this->findChildren<QStatusBar *>();
    foreach(QStatusBar *t, statusbars) t->hide();
}

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
void DrawingWindow::addLine(int x0, int y0, int x1, int y1, int width, QColor color) {
    Line *tmp = new Line(x0,y0,x1,y1, width, color, this);
    tmp->show();
    vL->push_back(tmp);
}

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
void DrawingWindow::addLinePolar(int x0, int y0, int length, double angle, int width, QColor color) {
    Line *tmp = new Line(x0,y0,length, angle, width, color, this);
    tmp->show();
    vL->push_back(tmp);
}



/// \fn void DrawingWindow::addTessellation(Tessellation &t)
/// \~English
/// \brief Add a tessalation to the window
/// \param t  a tessellation object
/// \~Spanish
/// \brief Anade un mosaico a la ventana
/// \param t un objeto de tipo tessellation (mosaico)
void DrawingWindow::addTessellation(Tessellation &t) {
    Tessellation *tmp = new Tessellation(this);
    tmp->move(t.x(),t.y());
    tmp->setRotation(t.getRotation());
    tmp->show();
    vT->push_back(tmp);
}

/// \fn DrawingWindow::~DrawingWindow()
/// \~English
/// \brief Destructor
/// \~Spanish
/// \brief Destructor
DrawingWindow::~DrawingWindow()
{
    foreach(Tessellation *t, *vT) delete t;
    delete vT;
    foreach(Line *l, *vL) delete l;
    delete vL;
    delete ui;
}


/// \fn void DrawingWindow::paintEvent(QPaintEvent *)
/// \~English
/// \brief Paints event.
/// \~Spanish
/// \brief Evento de pintar
void DrawingWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);
    QPen myPen;
    myPen.setWidth(1);
    myPen.setColor(QColor(0x0000ff));

    p.setPen(myPen);
    p.setBrush(Qt::cyan);

}
