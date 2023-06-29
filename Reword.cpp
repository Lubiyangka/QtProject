#include "Reword.h"

Reword::Reword(QWidget *parent) : QWidget(parent)
{

}
Reword::Reword(QRectF rewordNode,int nodeWidth,int nodeHeight):nodeWidth(nodeWidth),nodeHeight(nodeHeight){
    this->rewordNode=rewordNode;
}
QRectF Reword::getRewordNode(){
    return this->rewordNode;
}
void Reword::setRewordNode(QRectF rewordNode){
    this->rewordNode=rewordNode;
}
void Reword::addReword(){
    this->setRewordNode(QRectF(
                            qrand()%(this->width()/20)*20,
                            qrand()%(this->height()/20)*20,
                            nodeWidth,
                            nodeHeight));
}
void Reword::addReword(int rewordWidth,int rewordHeight){
    this->setRewordNode(QRectF(
                            qrand()%(this->width()/20)*20,
                            qrand()%(this->height()/20)*20,
                            rewordWidth,
                            rewordHeight));
}
