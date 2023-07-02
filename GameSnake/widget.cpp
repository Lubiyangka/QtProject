#include "widget.h"

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->setFixedSize(670,750);
    mGameView.setSceneRect(QRect(0,0,1000,1000));
    mScene.setSceneRect(QRect(0,0,1000,1000));
    path = "://img/bbg1.png";
    mBackGround1.setPixmap(QPixmap(path));
    mBackGround2.setPixmap(QPixmap(path));
    mTitle.setPixmap(QPixmap(":/img/title.png"));
    mBackGround2.setPos(-mBackGround2.pixmap().width(),0);
    mScene.addItem(&mBackGround1);//图片元素添加到场景
    mScene.addItem(&mBackGround2);
    mScene.addItem(&mTitle);
    mGameView.setScene(&mScene);//设置视图场景
    mGameView.setParent(this);//设置视图父亲为窗口
    mGameView.show();
    mBGMoveTimer = new QTimer(this);
    mBGMoveTimer->start(10);
    connect(mBGMoveTimer,&QTimer::timeout,this,&Widget::BGMove);
    ui->setupUi(this);
    QPushButton* btn1 = new QPushButton;
    connect(btn1,&QPushButton::clicked,this,&Widget::setStyle);
    this->setWindowTitle("贪吃蛇");
    btn1->setParent(this);
    btn1->setFlat(true);
    btn1->resize(100,55);
    btn1->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::BGMove()
{
    mBackGround2.moveBy(2,0);
    mBackGround1.moveBy(2,0);
    if(mBackGround1.x() >= mBackGround1.pixmap().width())
    {
        mBackGround1.setX(-mBackGround1.pixmap().width());
    }else if(mBackGround2.x() >= mBackGround2.pixmap().width())
    {
        mBackGround2.setX(-mBackGround2.pixmap().width());
    }

}
void Widget::setStyle()
{
    if(path == ":/img/bbg2.png")
    {
        path = "://img/bbg1.png";
        mBackGround1.setPixmap(QPixmap(path));
        mBackGround2.setPixmap(QPixmap(path));
    }
    else
    {
        path = ":/img/bbg2.png";
        mBackGround1.setPixmap(QPixmap(path));
        mBackGround2.setPixmap(QPixmap(path));
    }
}

void Widget::on_help_clicked()
{
    help* h = new help();
    this->hide();
    h->show();
}
QString Widget::getPath(){
    return this->path;
}


void Widget::on_play_clicked()
{
    Snake* s = new Snake;
    s->show();
    this->close();
    connect(s,&Snake::pauseTime,[s](){
        pause *p=new pause;
        p->show();
        s->hide();
        connect(p,&pause::buttonClicked,[s,p](){
            p->hide();
            s->show();
            s->startTime();
        });
    });
}

void Widget::on_play_2_clicked()
{
    TwoPlayers* t=new TwoPlayers;
    t->show();
    this->close();
}
