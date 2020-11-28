#ifndef TESSELATION_H
#define TESSELATION_H

#include <QWidget>
#include <QPainter>

/// \~English
/// A class to create tessellations.
/// \~Spanish
/// Una clase para crear mosaicos
class Tessellation : public QWidget
{
    Q_OBJECT
public:

    /// \fn Tessellation::Tessellation(QWidget *parent)
    /// \~English
    /// \brief Constructor. Creates a tesselation like this:
    /// ![http://i.imgur.com/WuMRMsi.png](http://i.imgur.com/WuMRMsi.png)
    /// \param parent  parent of this tesselation, you should pass a reference to the window
    /// where this tesselation 'lives'.
    /// \~Spanish
    /// \brief Constructor. Crea un mosaico como este: ![http://i.imgur.com/WuMRMsi.png](http://i.imgur.com/WuMRMsi.png)
    /// \param parent padre este mosaico, debes pasar una referencia a la ventana donde este mosaico 'reside'.
    explicit Tessellation(QWidget *parent = 0);

    /// \fn int Tessellation::getRotation()
    /// \~English
    /// \brief Getter for the rotation.
    /// \return The rotation
    /// \~Spanish
    /// \brief Devuelve la rotacion.
    /// \return La rotacion
    int getRotation();

    /// \fn int Tessellation::getWidth()
    /// \~English
    /// \brief Getter for the tesseltation width
    /// \return tesselation width
    /// \~Spanish
    /// \brief Devuelve el ancho del mosaico
    /// \return ancho del mosaico
    int getWidth();

    /// \fn int Tessellation::getHeight()
    /// \~English
    /// \brief Getter for the tesseltation height
    /// \return tesselation height
    /// \~Spanish
    /// \brief Devuelve la altura del mosaico
    /// \return altura del mosaico
    int getHeight();

    /// \fn void Tessellation::setRotation(int r)
    /// \~English
    /// \brief Setter for the tesselation rotation
    /// \param r tessellation rotation
    /// \~Spanish
    /// \brief Ajusta la rotacion del mosaico
    /// \param r rotacion para el mosaico
    void setRotation(int r);

    /// \fn void Tessellation::setWidth(int w)
    /// \~English
    /// \brief Setter for the tesselation width
    /// \param w tessellation width
    /// \~Spanish
    /// \brief Ajusta el ancho del mosaico
    /// \param w Ancho del mosaico
    void setWidth(int w);

    /// \fn void Tessellation::setHeight(int h)
    /// \~English
    /// \brief Setter for the tesselation height
    /// \param h tessellation height
    /// \~Spanish
    /// \brief Ajusta la altura del mosaico
    /// \param h Altura del mosaico
    void setHeight(int h);

signals:

public slots:

protected:
    /// \fn void Tessellation::paintEvent(QPaintEvent *)
    /// \~English
    /// \brief Paints a tessellation in the window every time that a paint event
    /// occurs.
    /// \~Spanish
    /// \brief Pinta un mosaico en la pantalla cada ves que ocurre un evento de
    /// pintar.
    void paintEvent(QPaintEvent *);
private:
    int rotation; /**< tesselation rotation / rotacion del mosaico */
    int width,    /**< tesselation width / ancho del mosaico */
    height;       /**< tesselation height / altura del mosaico */
};

#endif // TESSELATION_H
