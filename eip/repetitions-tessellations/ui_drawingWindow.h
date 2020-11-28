/********************************************************************************
** Form generated from reading UI file 'drawingWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWINGWINDOW_H
#define UI_DRAWINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawingWindow
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DrawingWindow)
    {
        if (DrawingWindow->objectName().isEmpty())
            DrawingWindow->setObjectName(QString::fromUtf8("DrawingWindow"));
        DrawingWindow->resize(400, 300);
        centralWidget = new QWidget(DrawingWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DrawingWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DrawingWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        DrawingWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DrawingWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DrawingWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DrawingWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DrawingWindow->setStatusBar(statusBar);

        retranslateUi(DrawingWindow);

        QMetaObject::connectSlotsByName(DrawingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DrawingWindow)
    {
        DrawingWindow->setWindowTitle(QCoreApplication::translate("DrawingWindow", "drawingWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawingWindow: public Ui_DrawingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWINGWINDOW_H
