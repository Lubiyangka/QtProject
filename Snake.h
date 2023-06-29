#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>

class Snake : public QWidget
{
    Q_OBJECT
public:
    explicit Snake(QWidget *parent = nullptr);
    int getNodeWidth();
    int getNodeHeight();
    void setNodeHeight(int);
    void setNodeWidth(int);
    void setSnakeSpeed(int);
private:
    int nodeWidth=20;
    int nodeHeight=20;
    int snakeSpeed=100;

signals:

};

#endif // SNAKE_H
