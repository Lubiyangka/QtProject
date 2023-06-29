#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QPointF>
#include <QPainter>
#include "Snake.h"
#include "Reword.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//方向
//enum Direct{
//    DirLeft,
//    DirRight,
//    DirUp,
//    DirDown,
//    Speed
//};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
//    //蛇
//    void addHead();
//    void addDown();
//    void addRight();
//    void addLeft();
//    void deleteTail();
//    //碰撞检测
//    bool checkContact();
//    //速度设置
//    void setLimitTime(int);
public slots:
//    void timeout();
protected:
//    //按键控制
//    void keyPressEvent(QKeyEvent *event);
//    void keyReleaseEvent(QKeyEvent *event);
//    //图像加载
//    void paintEvent(QPaintEvent *event);
private:
    //界面UI
    Ui::Widget *ui;
    //键盘隐射
//    int moveFalg;
//    //游戏开始/暂停
//    bool gameFlag=false;
//    //定时器
//    QTimer *timer;
//    int limitTime=200;
//    bool islongPressed=false;
//    //蛇
//    QList<QRectF> snake;
     Snake snake;
//    int nodeWidth=20;
//    int nodeHeight=20;
//    //果实
//    Reword node;
};
#endif // WIDGET_H
