#include "Twoplayers.h"

void TwoPlayers::addTop(){
    QPointF leftTop;
    QPointF rightBotom;
    if(snake[0].y() - nodeHeight < 0){
        leftTop = QPointF(snake[0].x(),this->height() - nodeHeight);
        rightBotom = QPointF(snake[0].x() + nodeWidth,this->height());
        snake.insert(0,QRectF(leftTop,rightBotom));
    }else{
        leftTop = QPointF(snake[0].x(),snake[0].y()-nodeHeight);
        rightBotom = snake[0].topRight();
        snake.insert(0,QRectF(leftTop,rightBotom));
    }
}
void TwoPlayers::addDown(){
    QPointF leftTop;
    QPointF rightBotom;
    if(snake[0].y() + nodeHeight > wheight ){
        leftTop = QPointF(snake[0].x(),0);
        rightBotom = QPointF(snake[0].x() + nodeWidth,nodeHeight);
        snake.insert(0,QRectF(leftTop,rightBotom));
    }else{
        leftTop = QPointF(snake[0].x(),snake[0].y()+nodeHeight);
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y()+nodeHeight);
        snake.insert(0,QRectF(leftTop,rightBotom));
    }
}
void TwoPlayers::addLeft(){
    QPointF leftTop;
    QPointF rightBotom;
    if(snake[0].x() - nodeWidth < 0 ){
        leftTop = QPointF(wwidth - nodeWidth,snake[0].y());
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y()+nodeHeight);
        snake.insert(0,QRectF(leftTop,rightBotom));
    }else{
        leftTop = QPointF(snake[0].x()-nodeWidth,snake[0].y());
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y()+nodeHeight);
        snake.insert(0,QRectF(leftTop,rightBotom));
    }
}
void TwoPlayers::addRight(){
    QPointF leftTop;
    QPointF rightBotom;
    if(snake[0].x() + nodeWidth > wwidth ){
        leftTop = QPointF(0,snake[0].y());
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y()+nodeHeight);
        snake.insert(0,QRectF(leftTop,rightBotom));
    }else{
        leftTop = QPointF(snake[0].x()+nodeWidth,snake[0].y());
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y()+nodeHeight);
        snake.insert(0,QRectF(leftTop,rightBotom));
    }
}

void TwoPlayers::deleteLast(){
    snake.removeLast();
}
