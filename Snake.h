#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QPainter>
//class Snake
class Snake : public QWidget
{
    Q_OBJECT
public:
    Snake(QWidget *parent = nullptr);
    //Snake(QWidget *parent=nullptr,int nodeWidth=20,int nodeHeight=20);
    void addHead(int height);
    void addDown(int height);
    void addRight(int width);
    void addLeft(int width);
    void deleteTail();
    bool intersects(QRectF rewordNodeRectF);
    bool checkContact();
//    void paintEvent(QPaintEvent *event);
//    int getNodeWidth();
//    int getNodeHeight();
//    void setNodeHeight(int);
//    void setNodeWidth(int);
//    void setSnakeSpeed(int);
private:
    QList<QRectF> snake;
    int nodeWidth=20;
    int nodeHeight=20;
    int snakeSpeed=100;
    QWidget * parent;
signals:

};

#endif // SNAKE_H
