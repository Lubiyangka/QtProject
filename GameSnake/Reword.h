#ifndef REWORD_H
#define REWORD_H

#include <QWidget>

class Reword : public QWidget
{
    Q_OBJECT
public:
    explicit Reword(QWidget *parent = nullptr);
    Reword(QRectF rewordNode,int nodeWidth=20,int nodeHeight=20);
    QRectF getRewordNode();
    void setRewordNode(QRectF);
    void addReword();
    void addReword(int,int);
private:
    QRectF rewordNode;
    int nodeWidth;
    int nodeHeight;
signals:

};

#endif // REWORD_H
