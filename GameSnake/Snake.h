#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QPointF>
#include <QPainter>
#include <QLabel>
#include <QToolButton>
#include <QPushButton>
#include "Reword.h"
enum Direct{
    DirLeft,
    DirRight,
    DirUp,
    DirDown,
    Speed
};
class Snake : public QWidget
{
    Q_OBJECT
public:
    Snake(QWidget *parent = nullptr);
    ~Snake();
    void setParent(QWidget *parent = nullptr);
    //蛇
    void addHead();
    void addDown();
    void addRight();
    void addLeft();
    void deleteTail();
    //碰撞检测
    bool checkContact();
    //速度设置
    void setLimitTime(int);
    void changeSnakeLength();
    void setNodeWidthAndHeight(int nodeWidth=20,int nodeHeight=20);
    void startTime();
    int score();
public slots:
    void timeout();
protected:
    //按键控制
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    //图像加载
    void paintEvent(QPaintEvent *event);
private:
    //窗口
    int windowWidth=1600;
    int windowHeight=900;
    //键盘隐射
    int moveFalg;
    //游戏开始/暂停
    bool gameFlag=false;
    //定时器
    QTimer* timer;
    int limitTime=80;
    bool islongPressed=false;
    int cntTime=0;
    //蛇
    QList<QRectF> snake;
    int initialLength=6;
    //Snake snaker;
    int nodeWidth=20;
    int nodeHeight=20;
    //果实
    Reword node;
signals:
    void pauseTime();
};

#endif // SNAKE_H
