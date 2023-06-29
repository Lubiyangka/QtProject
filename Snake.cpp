#include "Snake.h"

Snake::Snake(QWidget *parent) : QWidget(parent)
{
//    this->parent=parent;
//    QRectF rect(800,450,nodeWidth,nodeHeight);
//    snake.append(rect);
}
//Snake::Snake(QWidget *parent,int nodeWidth,int nodeHeight): QWidget(parent),nodeWidth(nodeWidth),nodeHeight(nodeHeight){

//}
//void Snake::addHead(int height){
//    QPointF leftTop;
//    QPointF rightBotom;
//    if(snake[0].y()-nodeHeight<0){
//        leftTop=QPointF(snake[0].x(),height-nodeHeight);
//        rightBotom=QPointF(snake[0].x()+nodeWidth,height);
//    }
//    else{
//        leftTop=QPointF(snake[0].x(),snake[0].y()-nodeHeight);
//        rightBotom=QPointF(snake[0].x()+nodeWidth,snake[0].y());
//    }
//    snake.insert(0,QRectF(leftTop,rightBotom));
//}
//void Snake::addDown(int height){
//    QPointF leftTop;
//    QPointF rightBotom;
//    if(snake[0].y()+nodeHeight*2>height){
//        leftTop=QPointF(snake[0].x(),0);
//        rightBotom=QPointF(snake[0].x()+nodeWidth,nodeHeight);
//    }
//    else{
//        leftTop=snake[0].bottomLeft();
//        rightBotom=snake[0].bottomRight()+QPointF(0,nodeHeight);
//    }
//    snake.insert(0,QRectF(leftTop,rightBotom));
//}
//void Snake::addRight(int width){
//    QPointF leftTop;
//    QPointF rightBotom;
//    if(snake[0].x()+nodeWidth*2>width){
//        leftTop=QPointF(0,snake[0].y());
//    }
//    else{
//        leftTop=snake[0].topRight();
//    }
//    rightBotom=leftTop+QPointF(nodeWidth,nodeHeight);
//    snake.insert(0,QRectF(leftTop,rightBotom));
//}
//void Snake::addLeft(int width){
//    QPointF leftTop;
//    QPointF rightBottom;
//    if(snake[0].x()-nodeWidth<0){
//        leftTop=QPointF(width-nodeWidth,snake[0].y());
//    }
//    else{
//        leftTop=snake[0].topLeft()-QPointF(nodeWidth,0);
//    }
//    rightBottom=leftTop+QPointF(nodeWidth,nodeHeight);

//    snake.insert(0,QRectF(leftTop,rightBottom));
//}
//void Snake::deleteTail(){
//    snake.removeLast();
//}
//bool Snake::intersects(QRectF rewordNodeRectF){
//    return snake[0].intersects(rewordNodeRectF);
//}
//bool Snake::checkContact(){
//    for(int i=0;i<snake.length();i++){
//        for(int j=i+1;j<snake.length();j++){
//            if(snake[i]==snake[j]){
//                return true;
//            }
//        }
//    }
//}
//void Snake::paintEvent(QPaintEvent *event){
//    QPainter painter(parent);
//    QPen pen;
//    QBrush brush;
//    //蛇
//    pen.setColor(Qt::black);
//    brush.setColor(Qt::darkMagenta);
//    brush.setStyle(Qt::SolidPattern);
//    painter.setPen(pen);
//    painter.setBrush(brush);
//    for(int i=0;i<snake.length();i++){
//        painter.drawRect(snake[i]);
//    }
//    QWidget::paintEvent(event);
//}
//int Snake::getNodeHeight(){
//    return nodeHeight;
//}
//void Snake::setNodeHeight(int nodeHeight){
//    this->nodeHeight=nodeHeight;
//}
//void Snake::setNodeWidth(int nodeWidth){
//    this->nodeWidth=nodeWidth;
//}
//void Snake::setSnakeSpeed(int snakeSpeed){
//    this->snakeSpeed=snakeSpeed;
//}
