#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QPointF>
#include <QPainter>
#include "Snake.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//方向
enum Direct{
    DirLeft,
    DirRight,
    DirUp,
    DirDown,
    Speed
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void timeout();
    void addHead();
    void addDown();
    void addRight();
    void addLeft();
    void addReword();
    void addTail();
    void deleteTail();
    bool checkContact();
    void setLimitTime(int);
protected:
    //按键控制
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    Ui::Widget *ui;
    int moveFalg;
    bool gameFlag=false;
    //定时器
    QTimer *timer;
    int limitTime=200;

    //蛇
    QList<QRectF> snake;
    Snake snaker;
    int nodeWidth=20;
    int nodeHeight=20;
    //果实
    QRectF rewordNode;
};
#endif // WIDGET_H
