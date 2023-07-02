#ifndef PAUSE_H
#define PAUSE_H
#include <QGraphicsPixmapItem>//图形元素
#include <QGraphicsView>//视图
#include <QGraphicsScene>//场景
#include "ui_pause.h"
#include <QDialog>
#include "widget.h"
namespace Ui {
class pause;
}

class pause : public QDialog
{
    Q_OBJECT

public:
    explicit pause(QWidget *parent = nullptr);
    ~pause();

public slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::pause *ui;
    QGraphicsView mview;//游戏视图
    QGraphicsScene mscene;
    QGraphicsPixmapItem bg1;
signals:
    void buttonClicked();
};

#endif // PAUSE_H
