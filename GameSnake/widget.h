#ifndef WIDGET_H
#define WIDGET_H
//#include"Widget.h"

#include <QWidget>
#include <QGraphicsPixmapItem>//图形元素
#include <QGraphicsView>//视图
#include <QGraphicsScene>//场景
#include <QPushButton>
#include <QTimer>
#include "ui_widget.h"
#include "help.h"
#include "pause.h"
#include "over.h"
#include "Snake.h"
#include "Twoplayers.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    ~Widget();

    //背景移动
    void BGMove();
    void setStyle();
    QString getPath();

private:
    Ui::Widget *ui;
    QString path;
    QPixmap p1;
    QGraphicsView mGameView;//游戏视图
    QGraphicsScene mScene;
    QGraphicsPixmapItem mBackGround1;
    QGraphicsPixmapItem mBackGround2;
    QGraphicsPixmapItem mTitle;
    QTimer* mBGMoveTimer;
private slots:
    void on_help_clicked();
    void on_play_clicked();
    void on_play_2_clicked();
};
#endif // WIDGET_H
