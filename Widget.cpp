#include "Widget.h"
#include "ui_Widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(1600,900);
    //设置定时器
    this->timer=new QTimer(this);
    //定时器有一个timeout信号
    //信号槽
    connect(timer,&QTimer::timeout,this,&Widget::timeout);
    //初始化蛇
    QRectF rect(800,450,nodeWidth,nodeHeight);
    snake.append(rect);
    addHead();
    addHead();
    addHead();
    addHead();
    addHead();
    addHead();
    addHead();
    addHead();
    addHead();
    addHead();
    this->node.addReword(nodeWidth,nodeHeight);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Up :
        if(moveFalg!=DirDown){
            moveFalg=DirUp;
        }
        break;
    case Qt::Key_Down :
        if(moveFalg!=DirUp){
            moveFalg=DirDown;
        }
        break;
    case Qt::Key_Right :
        if(moveFalg!=DirLeft){
            moveFalg=DirRight;
        }
        break;
    case Qt::Key_Left:
        if(moveFalg!=DirRight){
            moveFalg=DirLeft;
        }
        break;
    case Qt::Key_Space:
        if(event->isAutoRepeat()&&gameFlag){
            this->setLimitTime(10);
            this->timer->start(limitTime);
            this->islongPressed=true;
        }
        break;
    case Qt::Key_Escape:
        if(gameFlag==false){
            gameFlag=true;
            this->timer->start(limitTime);
            moveFalg=DirUp;
        }
        else{
            gameFlag=false;
            this->timer->stop();
        }
        break;
    default:
        break;
    }
}
void Widget::keyReleaseEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Space :
        if(!event->isAutoRepeat()&&islongPressed){
            this->setLimitTime(100);
            this->timer->start(limitTime);
        }
        break;
    default:
        break;
    }
}
//启动定时器，关联信号槽，实现对应的槽函数
void Widget::timeout(){
    int count=1;
//    if(snaker.intersects(node.getRewordNode())){
//        count++;
//        this->node.addReword(nodeWidth,nodeHeight);
//    }
    if(snake[0].intersects(node.getRewordNode())){
        count++;
        this->node.addReword(nodeWidth,nodeHeight);
    }
    while (count--) {
        switch (moveFalg) {
        case DirUp:
            //this->snaker.addHead(this->height());
            addHead();
            break;
        case DirDown:
            //this->snaker.addDown(this->height());
            addDown();
            break;
        case DirRight:
            //this->snaker.addRight(this->width());
            addRight();
            break;
        case DirLeft:
            //this->snaker.addLeft(this->width());
            addLeft();
            break;
        default:
            break;
        }
    }
    deleteTail();
    //this->snaker.deleteTail();
    update();
}
void Widget::addHead(){
    QPointF leftTop;
    QPointF rightBotom;
    if(snake[0].y()-nodeHeight<0){
        leftTop=QPointF(snake[0].x(),this->height()-nodeHeight);
        rightBotom=QPointF(snake[0].x()+nodeWidth,this->height());
    }
    else{
        leftTop=QPointF(snake[0].x(),snake[0].y()-nodeHeight);
        rightBotom=QPointF(snake[0].x()+nodeWidth,snake[0].y());
    }
    snake.insert(0,QRectF(leftTop,rightBotom));
}
void Widget::addDown(){
    QPointF leftTop;
    QPointF rightBotom;
    if(snake[0].y()+nodeHeight*2>this->height()){
        leftTop=QPointF(snake[0].x(),0);
        rightBotom=QPointF(snake[0].x()+nodeWidth,nodeHeight);
    }
    else{
        leftTop=snake[0].bottomLeft();
        rightBotom=snake[0].bottomRight()+QPointF(0,nodeHeight);
    }
    snake.insert(0,QRectF(leftTop,rightBotom));
}
void Widget::addRight(){
    QPointF leftTop;
    QPointF rightBotom;
    if(snake[0].x()+nodeWidth*2>this->width()){
        leftTop=QPointF(0,snake[0].y());
    }
    else{
        leftTop=snake[0].topRight();
    }
    rightBotom=leftTop+QPointF(nodeWidth,nodeHeight);
    snake.insert(0,QRectF(leftTop,rightBotom));
}
void Widget::addLeft(){
    QPointF leftTop;
    QPointF rightBottom;
    if(snake[0].x()-nodeWidth<0){
        leftTop=QPointF(this->width()-nodeWidth,snake[0].y());
    }
    else{
        leftTop=snake[0].topLeft()-QPointF(nodeWidth,0);
    }
    rightBottom=leftTop+QPointF(nodeWidth,nodeHeight);

    snake.insert(0,QRectF(leftTop,rightBottom));
}
void Widget::deleteTail(){
    snake.removeLast();
}
void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    QPen pen;
    QBrush brush;
    pix.load(":/background/material/20230218_205125 (13).png");
    painter.drawPixmap(0,0,1600,900,pix);
    //蛇
    pen.setColor(Qt::black);
    brush.setColor(Qt::darkMagenta);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    //画蛇
//    for(int i=0;i<this->snaker.getSnakeLength();i++){
//        painter.drawRect(this->snaker.getNode()[i]);
//    }
    for(int i=0;i<snake.length();i++){
        painter.drawRect(snake[i]);
    }
    //奖品
    pen.setColor(Qt::red);
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    //painter.drawEllipse(rewordNode);
    painter.drawEllipse(node.getRewordNode());
    if(checkContact()){
        QFont font("华文行楷",30,QFont::ExtraLight,false);
        painter.setFont(font);
        painter.drawText(
                    (this->width()-300)/2,
                    (this->height()-30)/2,
                    "GAME OVER!!");
        timer->stop();
    }
    QWidget::paintEvent(event);
}
bool Widget::checkContact(){
    for(int i=0;i<snake.length();i++){
        for(int j=i+1;j<snake.length();j++){
            if(snake[i]==snake[j]){
                return true;
            }
        }
    }
}
void Widget::setLimitTime(int limitTime){
    this->limitTime=limitTime;
}

