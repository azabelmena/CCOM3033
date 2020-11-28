// Todo implement game modes: 1= square upper left, 2 = rect upper left, etc..

#include "maingamewindow.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QEventLoop>
#include <QApplication>

//
// Initialices some of the data members
//

void MainGameWindow::initMembers() {
    s = new QGraphicsScene(this);

    s->setSceneRect(0,0,600,600);
    this->setGeometry(0,0,600,600);

    v = new QGraphicsView(s,this);
    v->setGeometry(0,0,600,600);

    pct_margin = .1;

    srand(time(NULL));

}

//
// Starts the timer that is used for animation purposes.
//

void MainGameWindow::startTheTimer() {
    timer = new QTimer(s);
    timer->connect(timer, SIGNAL(timeout()), s, SLOT(advance()));
    timer->start(10);
}

//
// Constructor that accepts a game mode argument. See the modes
// definition in the .h.
//

MainGameWindow::MainGameWindow(Mode gameMode) : QMainWindow(0) {
    initMembers();

    // the initial row/col positions of the robot
    uint initialX, initialY;

    _rows = rand() % 9 + 2;
    switch (gameMode) {
        case Mode::SQUARE_TOP_LEFT:
            _cols = _rows;
            initialX = initialY = 0;
            break;
        case Mode::RECT_TOP_LEFT:
            _cols = rand() % 9 + 2;
            initialX = initialY = 0;
            break;
        case Mode::RECT_RANDOM:
            _cols = rand() % 9 + 2;
            initialX = rand() % _cols;
            initialY = rand() % _rows;
            break;
        case Mode::PYRAMID_RANDOM:
            _cols = (rand() % 4 + 2) * 2 + 1;
            createPiramid();
            assignValidPos(initialX, initialY);
            break;
    }

    // This creates rectangular mazes
    if (_maze == "") {
        for (uint r = 0; r < _rows; r++) {
            for (uint c = 0; c < _cols; c++) {
                _maze.push_back('x');
            }
            _maze.push_back('\n');
        }
    }

    qDebug() << "MainGameWindow::MainGameWindow(): width: " << this->width();
    qDebug() << "_maze: " << _maze;

    paintMaze(initialX, initialY);

    startTheTimer();

    v->show();
}


// Creates this type of pyramid, e.g. _cols = 7
// 000x000
// 00xxx00
// 0xxxxx0
// xxxxxxx

void MainGameWindow::createPiramid() {
    _maze = "";
    _rows = _cols/2;


    for (uint r = 0; r <= _rows + 1; r++) {
        for (uint c = 0; c < _cols; c++) {
            _maze.push_back( abs((int)c - (int)_rows) <= (int)r ? 'x':' ');
        }
        _maze.push_back('\n');
    }

    _rows++;
}


//
// Randomly determines a valid initial position for the robot
//

void MainGameWindow::assignValidPos(uint &initialX, uint &initialY) {
    qDebug() << _maze;
    if (_cols <= 0 || _rows <= 0) {
        qDebug() << "assignValidPos was called with 0 rows or cols!";
        exit(1);
    }

    // throw the dice to determine initial random position
    do {
        initialX = rand() % _cols;
        initialY = rand() % _rows;
    } while (_maze.toStdString()[initialY * (_cols + 1) + initialX] != 'x');
}

//
// Constructor that accepts number of rows and columns.
//

MainGameWindow::MainGameWindow(uint rows, uint cols) : QMainWindow(0) {
    _rows = rows;
    _cols = cols;

    initMembers();

    _maze = "";
    for (uint r = 0; r < _rows; r++) {
        for (uint c = 0; c < _cols; c++) {
            _maze.push_back('x');
        }
        _maze.push_back('\n');
    }

    qDebug() << "MainGameWindow::MainGameWindow(): width: " << this->width();
    qDebug() << "_maze: " << _maze;

    paintMaze(0,0);

    startTheTimer();

    v->show();
}

MainGameWindow::MainGameWindow(const QString &maze) {
    _maze = maze;
    initMembers();

    if (validMaze() ) {
        qDebug() << "valid maze!!!!";
        paintMaze(0,0);
        startTheTimer();
    }

}

//
// Given a string that represents the maze, determines the number
// of rows and cols. Returns false if the maze is malformed.
//

bool MainGameWindow::validMaze() {
    char c;
    uint ctr = 0;
    _cols = 0; _rows = 0;
    for (int i = 0; i < _maze.length(); i++){
        c = _maze.toStdString()[i];
        if (c == 'x' || c == ' ') ctr++;
        else if (c == '\n') {
            if (_cols == 0) _cols = ctr;
            else if (_cols != ctr) return false;
            ctr = 0;
            _rows++;
        }
    }
    qDebug() << "rows:" << _rows << " cols: " << _cols;
    return true;
}

//
// This is a delay that lets other events in the event loop
// continue executing.
//

void delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while( QTime::currentTime() < dieTime )
        QApplication::processEvents(QEventLoop::AllEvents,10);
}

//
// Determines the underlying character of the maze.
// This is used to determine if the robot is off the grid
// or has entered a wall.
//

char MainGameWindow::posToChar() {
    uint r, c;

    posToRC(r, c);

    if (r >= _rows || c >= _cols) return -1;
    return _maze.toStdString()[r * (_cols + 1) + c];

}

//
// Determines the poisition in row, column, based on the x, y position
// of the robot.
//

void MainGameWindow::posToRC(uint &r, uint &c) {
    uint realX = robot->myX - s->width() *  pct_margin;
    uint realY = robot->myY - s->height() * pct_margin ;

    r = round(static_cast<float>(realY) / rowHeight);
    c = round(static_cast<float>(realX) / colWidth);
}

//
// Given the direction determines if the robot may move in that
// direction.
//

bool MainGameWindow::canMove(char dir) {

    uint r, c;

    posToRC(r, c);

    switch(dir) {
    case 'W': c--; break;
    case 'E': c++; break;
    case 'N': r--; break;
    case 'S': r++; break;
    default:
        display("Bad direction: " + QString(dir));
        return false;
    }

    if (r >= _rows || c >= _cols) return false;
    else return _maze.toStdString()[r * (_cols + 1) + c] == 'x';
}


//
// Given a character 'N', 'S', 'E', or 'W', moves the robot
// one cell in that direction. If the target cell was invalid
// then it destroys the robot.
//

void MainGameWindow::moveRobot(char dir) {
    if (robot->isAlive()) {
        uint deltaX = colWidth / 10;
        uint deltaY = rowHeight / 10;

        qDebug() << "car at:" << robot->myX;
        switch(dir) {
        case 'N': robot->toY = robot->myY - rowHeight; robot->myDirY = -deltaY; break;
        case 'S': robot->toY = robot->myY + rowHeight; robot->myDirY = +deltaY; break;
        case 'E': robot->toX = robot->myX + colWidth;  robot->myDirX = +deltaX; break;
        case 'W': robot->toX = robot->myX - colWidth;  robot->myDirX = -deltaX; break;
        default: display("Bad direction: " + QString(dir)); return;
        }

        qDebug() <<"colwidth" << colWidth;
        qDebug() << "move to at:" << robot->toX;

        while (robot->myDirX != 0 || robot->myDirY != 0)
            delay(500);
        robot->myDirX = robot->myDirY = 0;

        if (posToChar() != 'x')
            robot->kill();
   }
}

//
// Given a string, displays it in large letters.
//

void MainGameWindow::display(const QString &st) {
    if (robot->isAlive()) {
        msg->setHtml("<center>" + st + "</center>");
        msg->show();
        delay(500);
        msg->hide();
    }
}

//
// Given an int, displays it in big letters.
//

void MainGameWindow::display(int n) {
    display(QString::number(n));
}


// Paints the maze based on the contents of the _maze string.
// Also creates the robot and the text box for display.

void MainGameWindow::paintMaze(uint initialX, uint initialY) {

    pct_margin = 1.0/( _cols > _rows ? _cols + 2 : _rows + 2);

    qDebug() << "pct_margin " << pct_margin;
    uint fromY = s->height()*pct_margin, toY = s->height()*(1-pct_margin);

    qDebug() << "toX, toY" << fromY << "," << toY ;
    uint fromX = s->width()*pct_margin,  toX = s->width()*(1-pct_margin);

    rowHeight = (toY - fromY) / _rows;
    colWidth =  (toX - fromX) / _cols;


    uint strPos = 0;
    QBrush black(Qt::black);
    QBrush white(Qt::white);

    for (uint i = 0; i < _rows; i++) {
        uint y = i * rowHeight + s->height()*pct_margin;
        for (uint j = 0; j < _cols; j++) {
            uint x = j * colWidth + s->width() * pct_margin;
            qDebug() << x << " " << y;
            s->addRect(x, y, colWidth, rowHeight, QPen(Qt::SolidLine),
                       _maze.at(strPos) == 'x' ? white : black);
            strPos++;
        }
        strPos++;
    }

    // // Create the robot
    //
    // int initialX, initialY;
    //
    // // throw the dice to determine initial random position
    // do {
    //     initialX = rand() % _cols;
    //     initialY = rand() % _rows;
    //
    // } while (_maze.toStdString()[initialY * (_cols + 1) + initialX] != 'x');

    robot = new GenericScrollingObject(":robot.png", s,
                                       colWidth * initialX  + s->width() * pct_margin,
                                       rowHeight * initialY + s->height() * pct_margin, colWidth,rowHeight,
                                       QColor(Qt::white), this);


    // Create the text box that will be used for the display

    msg = new QGraphicsTextItem;
    msg->setPos(0, s->height()/2);
    msg->setTextWidth(s->width());
    msg->setHtml("<center>Barev</center>");
    msg->setFont(QFont("Helvetica",90));
    msg->setDefaultTextColor(Qt::green);
    msg->hide();
    s->addItem(msg);

}
