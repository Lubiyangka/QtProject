#include "Snake.h"

Snake::Snake(QWidget *parent) : QWidget(parent)
{

}
int Snake::getNodeWidth(){
    return nodeWidth;
}
int Snake::getNodeHeight(){
    return nodeHeight;
}
void Snake::setNodeHeight(int nodeHeight){
    this->nodeHeight=nodeHeight;
}
void Snake::setNodeWidth(int nodeWidth){
    this->nodeWidth=nodeWidth;
}
void Snake::setSnakeSpeed(int snakeSpeed){
    this->snakeSpeed=snakeSpeed;
}
