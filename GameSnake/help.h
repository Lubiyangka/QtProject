#ifndef HELP_H
#define HELP_H
#include <QGraphicsPixmapItem>//图形元素
#include <QGraphicsView>//视图
#include <QGraphicsScene>//场景
#include <QGraphicsEffect>
#include <QDialog>
#include "ui_help.h"
#include "widget.h"

namespace Ui {
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();

private slots:
    void on_pushButton_clicked();

private:
    Ui::help *ui;
    QGraphicsView mview;//游戏视图
    QGraphicsScene mscene;
    QGraphicsPixmapItem bg1;
};

#endif // HELP_H
