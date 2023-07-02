#include "over.h"

over::over(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::over)
{
    this->setWindowTitle("帮助");
    this->setFixedSize(1000,560);
    mview.setSceneRect(QRect(0,0,1000,700));
    mscene.setSceneRect(QRect(0,0,1000,700));
    QString pt = "://img/over.png";
    bg1.setPixmap(QPixmap(pt));
    mscene.addItem(&bg1);
    mview.setScene(&mscene);
    mview.setParent(this);
    mview.show();
    ui->setupUi(this);
}

over::~over()
{
    delete ui;
}

void over::on_pushButton_clicked()
{
    qApp->quit();
}

void over::on_pushButton_2_clicked()
{
    Widget* w = new Widget();
    w->show();
    this->hide();
}
