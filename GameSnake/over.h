#ifndef OVER_H
#define OVER_H
#include <QGraphicsPixmapItem>//图形元素
#include <QGraphicsView>//视图
#include <QGraphicsScene>//场景
#include <QDialog>
#include "ui_over.h"
#include "widget.h"

namespace Ui {
class over;
}

class over : public QDialog
{
    Q_OBJECT

public:
    explicit over(QWidget *parent = nullptr);
    ~over();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QGraphicsView mview;//游戏视图
    QGraphicsScene mscene;
    QGraphicsPixmapItem bg1;
    Ui::over *ui;
};

#endif // OVER_H
