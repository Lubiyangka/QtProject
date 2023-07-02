#include "help.h"

help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    this->setWindowTitle("帮助");
    this->setFixedSize(1000,700);
    mview.setSceneRect(QRect(0,0,1000,700));
    mscene.setSceneRect(QRect(0,0,1000,700));
    QString pt = ":/img/bbbg.jpg";
    bg1.setPixmap(QPixmap(pt));
    mscene.addItem(&bg1);
    mview.setScene(&mscene);
    mview.setParent(this);
    mview.show();
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}

void help::on_pushButton_clicked()
{
    Widget* w = new Widget();
    w->show();
    this->hide();
}
