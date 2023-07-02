#include "pause.h"

pause::pause(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pause)
{
    this->setWindowTitle("帮助");
    this->setFixedSize(660,700);
    mview.setSceneRect(QRect(0,0,1000,700));
    mscene.setSceneRect(QRect(0,0,1000,700));
    QString pt = "://img/pbg.jpg";
    bg1.setPixmap(QPixmap(pt));
    mscene.addItem(&bg1);
    mview.setScene(&mscene);
    mview.setParent(this);
    mview.show();
    //connect(ui->pushButton_3, &QPushButton::clicked, this, &pause::handleReturnClicked);
    ui->setupUi(this);
}

pause::~pause()
{
    delete ui;
}

void pause::on_pushButton_clicked()
{
    Widget* w = new Widget();
    w->show();
    this->hide();
}

void pause::on_pushButton_3_clicked()
{
    buttonClicked();
}
