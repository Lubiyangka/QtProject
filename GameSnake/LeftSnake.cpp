#include "Twoplayers.h"
//#include "ui_widget.h"
#include <qpainter.h>
#include <math.h>
#include <qdebug.h>
#include <qthread.h>
#include <qdialog.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qcolor.h>

void TwoPlayers::addTop1(){
    QPointF leftTop;
    QPointF rightBotom;
    if(snake1[0].y() - nodeHeight < 0){
        leftTop = QPointF(snake1[0].x(),this->height() - nodeHeight);
        rightBotom = QPointF(snake1[0].x() + nodeWidth,this->height());
        snake1.insert(0,QRectF(leftTop,rightBotom));
    }else{
        leftTop = QPointF(snake1[0].x(),snake1[0].y()-nodeHeight);
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y()+nodeHeight);
        snake1.insert(0,QRectF(leftTop,rightBotom));
    }
}
void TwoPlayers::addDown1(){
    QPointF leftTop;
    QPointF rightBotom;
    if(snake1[0].y() + nodeHeight > wheight ){
        leftTop = QPointF(snake1[0].x(),0);
        rightBotom = QPointF(snake1[0].x() + nodeWidth,nodeHeight);
        snake1.insert(0,QRectF(leftTop,rightBotom));
    }else{
        leftTop = QPointF(snake1[0].x(),snake1[0].y()+nodeHeight);
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y()+nodeHeight);
        snake1.insert(0,QRectF(leftTop,rightBotom));
    }
}
void TwoPlayers::addLeft1(){
    QPointF leftTop;
    QPointF rightBotom;
    if(snake1[0].x() - nodeWidth < 0 ){
        leftTop = QPointF(wwidth - nodeWidth,snake1[0].y());
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y()+nodeHeight);
        snake1.insert(0,QRectF(leftTop,rightBotom));
    }else{
        leftTop = QPointF(snake1[0].x()-nodeWidth,snake1[0].y());
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y()+nodeHeight);
        snake1.insert(0,QRectF(leftTop,rightBotom));
    }
}
void TwoPlayers::addRight1(){

    QPointF leftTop;
    QPointF rightBotom;
    if(snake1[0].x() + nodeWidth > wwidth ){
        leftTop = QPointF(0,snake1[0].y());
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y()+nodeHeight);
        snake1.insert(0,QRectF(leftTop,rightBotom));
    }else{
        leftTop = QPointF(snake1[0].x()+nodeWidth,snake1[0].y());
        rightBotom = QPointF(leftTop.x()+nodeWidth,leftTop.y() + nodeHeight);
        snake1.insert(0,QRectF(leftTop,rightBotom));
    }
}

void TwoPlayers::deleteLast1(){
    snake1.removeLast();
}
