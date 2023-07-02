#include "Snake.h"
Snake::Snake(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(windowWidth,windowHeight);
    this->setWindowTitle("单人模式");
    //设置定时器
    this->timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Snake::timeout);

    QRectF rect(800,450,nodeWidth,nodeHeight);
    snake.append(rect);
    for(int i=0;i<initialLength;i++){
        addHead();
    }
    QToolButton *button = new QToolButton(this);
    button->setIcon(QIcon(":/background/img/menu.png"));
    button->setText("Button");
    button->setFixedSize(60, 60);
    button->setIconSize(button->size());
    connect(button,&QToolButton::clicked,[this](){
        gameFlag=false;
        pauseTime();
        this->timer->stop();
    });
//    pause* p=new pause;
//    connect(this,&Snake::pauseGame,[p,this](){
//        p->show();
//        this->hide();
//    });
//    connect(button,&QToolButton::clicked,[p,this](){
//        p->show();
//        this->hide();
//    });
//    connect(this,&Snake::pauseGame,this,&Snake::newPause);
//    connect(button,&QToolButton::clicked,this,&Snake::newPause);
    QLabel* label=new QLabel(this);
    label->setGeometry(1400,0,200,50);
    label->setText("分数:"+QString::number(this->score()));
    QFont *labelFont=new QFont("楷体",20,5) ;
    label->setFont(*labelFont);
    connect(timer,&QTimer::timeout,[label,this](){
        label->setText("分数:"+QString::number(this->score()));
    });
    this->node.addReword(20,20);
}
Snake::~Snake(){
    delete timer;
    //delete p;
}
void Snake::setParent(QWidget *parent){
    QWidget::setParent(parent);
}
void Snake::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_W :
        if(moveFalg!=DirDown){
            moveFalg=DirUp;
        }
        break;
    case Qt::Key_S :
        if(moveFalg!=DirUp){
            moveFalg=DirDown;
        }
        break;
    case Qt::Key_A :
        if(moveFalg!=DirLeft){
            moveFalg=DirRight;
        }
        break;
    case Qt::Key_D:
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
            startTime();
        }
        else{
            gameFlag=false;
            pauseTime();
            this->timer->stop();
        }
        break;
    default:
        break;
    }
    QWidget::keyPressEvent(event);
}
void Snake::keyReleaseEvent(QKeyEvent *event){
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
    QWidget::keyReleaseEvent(event);
}
//启动定时器，关联信号槽，实现对应的槽函数
void Snake::timeout(){
    int count=1;
    if(snake[0].intersects(node.getRewordNode())){
        count++;
        this->node.addReword(20,20);
    }
    while (count--) {
        switch (moveFalg) {
        case DirUp:
            addHead();
            break;
        case DirDown:
            addDown();
            break;
        case DirRight:
            addRight();
            break;
        case DirLeft:
            addLeft();
            break;
        default:
            break;
        }
    }
    deleteTail();
    update();
}
int Snake::score(){
    return this->snake.length()-initialLength-1;
}
void Snake::addHead(){
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
void Snake::addDown(){
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
void Snake::addRight(){
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
void Snake::addLeft(){
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
void Snake::deleteTail(){
    snake.removeLast();
}
void Snake::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    QPen pen;
    QBrush brush;
    pix.load(":/background/img/bc.png");
    painter.drawPixmap(0,0,1600,900,pix);
    //蛇
    pen.setColor(Qt::black);
    brush.setColor(Qt::darkMagenta);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    //画蛇
    foreach(const QRectF& s,snake){
        painter.drawRect(s);
    }
    //奖品
    pen.setColor(Qt::red);
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(node.getRewordNode());
    //结束文字
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
bool Snake::checkContact(){
    for(int i=0;i<snake.length();i++){
        for(int j=i+1;j<snake.length();j++){
            if(snake[i]==snake[j]){
                return true;
            }
        }
    }
}
void Snake::setLimitTime(int limitTime){
    this->limitTime=limitTime;
}
void Snake::changeSnakeLength(){
    int nodeLength=0;
    //bool flag=false;
    int snakeLengthTime=snake.length()/5;
    if(snake.length()==5){
        nodeLength=4;
        setNodeWidthAndHeight(nodeWidth+nodeLength,nodeHeight+nodeLength);
    }
    else if(snake.length()==10){
        for(int i=0;i<snakeLengthTime;i++){
            nodeLength+=20;
        }
        setNodeWidthAndHeight(nodeWidth+nodeLength,nodeHeight+nodeLength);
    }
    if(snake.length()==5){
    for(int i=0;i<snake.length();i++){
        snake[i].setWidth(40);
        snake[i].setHeight(40);
    }}

}
void Snake::setNodeWidthAndHeight(int nodeWidth,int nodeHeight){
    this->nodeWidth=nodeWidth;
    this->nodeHeight=nodeHeight;
}
void Snake::startTime(){
    gameFlag=true;
    if(cntTime==0){
        moveFalg=DirUp;
    }
    cntTime++;
    this->timer->start(limitTime);
}

